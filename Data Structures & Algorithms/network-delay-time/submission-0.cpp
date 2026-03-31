class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;

        unordered_map<int,vector<pair<int,int>>> adj;
        unordered_set<int> visited;

        for(const vector<int>& v: times){
            adj[v[0]].push_back({v[1],v[2]});
        }


        qu.push({0,k});

        while(!qu.empty()){
            int cumulative_time = qu.top().first;
            int node = qu.top().second;

            visited.insert(node);

            if(visited.size()== n) return cumulative_time;
            qu.pop();

            for(const pair<int,int>& p: adj[node]){
                if(visited.find(p.first)==visited.end()){
                    qu.push({cumulative_time+p.second, p.first});
                }
            }
        }

        return -1;

        
    }
};
