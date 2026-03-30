class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(const vector<int> nei: edges){
            adj[nei[0]].push_back(nei[1]);
            adj[nei[1]].push_back(nei[0]);
        }


        vector<bool>vis(n, false);

        int num = 0;


        for(int i=0;i<n;i++){
            if(!vis[i]){
                num++;
                dfs(i,-1,adj,vis);
            }
        }

        return num;
    }

    void dfs(int node, int parent, const vector<vector<int>>& adj, vector<bool> & vis){
        vis[node] = true;
        for(int nei: adj[node]){
            if(!vis[nei]) dfs(nei, node, adj, vis);
        }
    }
};
