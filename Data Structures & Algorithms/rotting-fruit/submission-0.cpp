class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;

        queue<pair<pair<int,int>,int>> qu;

        for(int i=0; i<grid.size();i++)
        for(int j=0; j<grid[0].size(); j++)
            if(grid[i][j]==2) qu.push({{i,j},0});

        while(!qu.empty()){
            int i = qu.front().first.first;
            int j = qu.front().first.second;

            int t = qu.front().second;

            qu.pop();

            minutes = max(minutes,t);

            for(int k=-1;k<2;k++)
                for(int l=-1;l<2;l++){
                    if((k==0 || l==0) && i+k>=0 && i+k<grid.size() && j+l>=0 && j+l<grid[0].size() && grid[i+k][j+l]==1){
                        grid[i+k][j+l] = 2;
                        qu.push({{i+k,j+l},t+1});
                    }
                }


        }   

        for(int i=0; i<grid.size();i++)
        for(int j=0; j<grid[0].size(); j++)
            if(grid[i][j]==1) return -1;

        return minutes;    

    }
};
