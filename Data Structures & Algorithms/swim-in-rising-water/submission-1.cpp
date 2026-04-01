class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< pair<int,pair<int,int>>, vector< pair<int,pair<int,int>> >, greater< pair< int, pair<int,int> >> > pq;
        pq.push({grid[0][0],{0,0}});
                    grid[0][0] = -1;


        while(!pq.empty()){
            int maxi = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();


            if(i==grid.size()-1 && j==grid.size()-1){
                return maxi;
            }

            else{
                for(int k=-1;k<2;k++)
                    for(int l=-1;l<2;l++)
                        if((k==0||l==0) && i+k>=0 && i+k<grid.size() && j+l>=0 && j+l<grid.size() && grid[i+k][j+l]!=-1){
                            pq.push({max(maxi,grid[i+k][j+l]),{i+k,j+l}});
                            grid[i+k][j+l] = -1;
                        }
            }


        } 

        return -1;
    }
};
