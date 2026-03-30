class Solution {
public:
    pair<int,int> dfs(int n, unordered_set<int>& vis, int par, const vector<vector<int>>& adj, unordered_set<int>& cycle ){
        vis.insert(n);
        pair<int,int> ans;
        for(int nei: adj[n]){
            if(nei!=par){
                if(vis.find(nei) != vis.end()){
                    cycle.insert(nei);   
                    cycle.insert(n);     
                    return {nei,max(n,nei)};

                }
                else{
                pair<int,int> p = dfs(nei,vis,n,adj,cycle);
                if(p.first == n){
                    cycle.insert(n);
                    return{-1, p.second};
                }
                else if(p.first == -1){ 
                    return p;
                }
                else if(p.first == 0) continue;
                else{
                    cycle.insert(n);
                     return {
                    p.first, max(n,p.second)
                };}
            }
            }
           
        }

        return {0,INT_MIN};

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size()+1);

        for(vector<int> & edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        unordered_set<int> cycle;

        int max = dfs(1,vis,-1, adj,cycle).second;
        for(int i: cycle ) cout << i << " " ;
        cout << endl;    
        

        for(auto rit = edges.rbegin(); rit != edges.rend(); ++rit){
            if(cycle.find((*rit)[0])!=cycle.end() && cycle.find((*rit)[1])!=cycle.end()) return *rit;
                
        }
        return{-1,-1};
    }
};
