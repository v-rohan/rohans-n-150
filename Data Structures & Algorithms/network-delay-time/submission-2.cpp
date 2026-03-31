class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> qu;

        unordered_map<int,vector<pair<int,int>>> adj;
        unordered_set<int> visited;

        vector<int>d(n+1,INT_MAX);

        for(const vector<int>& v: times){
            adj[v[0]].push_back({v[1],v[2]});
        }


        qu.push({0,k});

        

        while(!qu.empty()){
            int cumulative_time = qu.top().first;
            int node = qu.top().second;
            qu.pop();

            d[node] = min(cumulative_time,d[node]);

            if(visited.find(node)!=visited.end()) continue;
            visited.insert(node);

            if(visited.size()== n) return cumulative_time;

            for(const pair<int,int>& p: adj[node]){
                if(visited.find(p.first)==visited.end() && d[p.first]>cumulative_time+p.second){
                    qu.push({cumulative_time+p.second, p.first});
                }
            }
        }

        return -1;

        
    }
};
