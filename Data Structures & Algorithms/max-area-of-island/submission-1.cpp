class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& grid, int ip, int jp){
        grid[i][j] = 0;
        int area = 1;
        for(int k=-1;k<=1;k++){
            for(int l = -1; l<=1; l++){
                if(k==0 || l==0)
                if(i+k>=0 && i+k<grid.size() && j+l>=0 && j+l<grid[0].size()&& grid[i+k][j+l]==1){
                    area+=dfs(i+k,j+l, grid, i,j);
                }
            }
        }

        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int c = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    c = max(c,dfs(i,j,grid,-1, -1));}
            }
        }

        return c;
    }
    
};
