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
        priority_queue<pair<int,pair<pair<int,int>,pair<int,int>>>, vector<pair<int,pair<pair<int,int>,pair<int,int>>>>, greater<pair<int,pair<pair<int,int>,pair<int,int>>>> >pq;

        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i!=j){
                    pq.push({(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])), { {points[i][0],points[i][1]}, {points[j][0],points[j][1]} }  });
                }
            }
        }


        unordered_set<pair<int,int>, hashFunction> con;

        unordered_set<pair<int,int>, hashFunction> noncon;

        for(const vector<int> point:points){
            noncon.insert({point[0],point[1]});
        }

        int total = 0;
        while(!pq.empty()){
            int cost_curr = pq.top().first;
            pair<int,int> p1 = pq.top().second.first;
            pair<int,int> p2 = pq.top().second.second;
            pq.pop();
            if(con.size()==0){
                noncon.erase(p1);
                con.insert(p1);

                noncon.erase(p2);
                con.insert(p2);

                total += cost_curr; 
            }
            else{
                if((con.find(p1) != con.end() && noncon.find(p2)!=noncon.end()) || (con.find(p2) != con.end() && noncon.find(p1)!=noncon.end()) ){
                    pair<int,int> in_non_con = noncon.find(p1)!=noncon.end()?p1:p2;
                    noncon.erase(in_non_con);
                    con.insert(in_non_con);
                    total+=cost_curr;

                    if(noncon.size()==0) break;
                }
            }
        }

        return total;


    }
};
