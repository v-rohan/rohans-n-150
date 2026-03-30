class Solution {
public:

    bool dfs(int i, const vector<vector<int>>& adj, int par, unordered_set<int>& vis, vector<bool>&visited){
        vis.insert(i);
        cout << i << endl;
        visited[i] = true;
        for(int nei: adj[i]){
            cout << i << " -> " << nei << endl;
            if(nei != par){
            if(vis.find(nei)!=vis.end()) return false;
            if(!dfs(nei,adj,i,vis,visited)) return false;
            }
        }
        vis.erase(i);
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const vector<int> & i: edges){
            adj[i[0]].push_back(i[1]);
                        adj[i[1]].push_back(i[0]);

        } 

        unordered_set<int> vis;
        vector<bool>visited(n,false); 
        for(int i=0; i<n; i++){
            if(!visited[i] && !dfs(i,adj,-1,vis,visited)) return false;
            vis.clear();
        }

        bool corr = true;
        for(bool v: visited){
            corr = corr && v;
        }

        return corr;            
    }
};
