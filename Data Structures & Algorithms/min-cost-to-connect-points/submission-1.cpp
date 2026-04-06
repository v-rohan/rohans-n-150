
    struct DisjointSet {
   vector<int> parent;
   vector<int> rank;


    DisjointSet(int n ) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i; // Each element is its own representative
    }

    int findPar(int x){
        if(parent[x]==x) return x;
        else return parent[x] = findPar(parent[x]); 
    }

    void unite(int x, int y){
        int u_p_x = findPar(x);
        int u_p_y = findPar(y);

        if(u_p_x == u_p_y) return;
        if(rank[u_p_x]>rank[u_p_y]){
            parent[u_p_y] = u_p_x;
        }
        else if(rank[u_p_x]<rank[u_p_y]){
            parent[u_p_x] = u_p_y;
        }
        else{
           parent[u_p_x] = u_p_y;
           rank[u_p_y]++;
        }
    }

    bool connected(int x, int y){
        return findPar(x) == findPar(y);
    }
};
class Solution {
public:
struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

    

    int minCostConnectPoints(vector<vector<int>>& points) {

        priority_queue<pair<int,pair<int,int>>,  vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;

        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    pq.push({(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])), {i,j}});
                }
            }
        }



        DisjointSet ds(points.size());

        int total = 0;

        while(!pq.empty()){
            pair<int, pair<int,int>> pi = pq.top();
            pq.pop();


            if(!ds.connected(pi.second.second, pi.second.first)){
                ds.unite(pi.second.first, pi.second.second);
                            total += pi.first;
            }

        }

        return total;




    }
};
