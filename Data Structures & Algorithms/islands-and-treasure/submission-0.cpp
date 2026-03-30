class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> qu;


        for(int i=0; i<grid.size(); i++)
            for(int j =0 ; j<grid[0].size(); j++)
                if(grid[i][j] == 0) qu.push({i,j});


        while(!qu.empty()){
            pair<int,int> co = qu.front();

            qu.pop();

            for(int i=-1;i<2; i++)
                for(int j=-1; j<2; j++)
                    if(i==0 || j==0){
                        if(co.first+i>=0 && co.first+i<grid.size() && co.second+j>=0 && co.second+j<grid[0].size() && grid[co.first+i][co.second+j] == INT_MAX ){
                            grid[co.first+i][co.second+j] = grid[co.first][co.second] +1;
                            qu.push({co.first+i,co.second+j});
                        }
                    }
                
        }        
    }
};
