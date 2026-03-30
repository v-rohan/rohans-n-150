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
            if(!dfs(0,adj,-1,vis,visited)) return false;
        
        // problem with this is that it will fail for [[0,1],[2,3]] they are valid individual ones, but rerunnign dfs, makes disconnected oomponenets look connected  

        bool corr = true;
        for(bool v: visited){
            corr = corr && v;
        }

        return corr;            
    }
};
