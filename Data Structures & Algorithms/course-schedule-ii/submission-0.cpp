class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(const vector<int>& t: prerequisites){
            adj[t[1]].push_back(t[0]);
            indegree[t[0]]++;
        }

        queue<int> bfsq;

        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0) bfsq.push(i);
        }

        vector<int> ord;

        while(!bfsq.empty()){
            int currIndex = bfsq.front();

            bfsq.pop();

            ord.push_back(currIndex);

            for(int i: adj[currIndex]){
                indegree[i]--;
                if(indegree[i]==0) bfsq.push(i);
            }
            
        }

       if(ord.size() != numCourses){
        ord.clear();
       }
        return ord;
       
    }

    
};
