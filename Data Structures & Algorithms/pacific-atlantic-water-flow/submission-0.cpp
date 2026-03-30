class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pair<int,int>> pac;
        queue<pair<int,int>> atl;


        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> paci(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atli(ROWS, vector<bool>(COLS, false));


        for(int j=0; j<heights[0].size(); j++){
            atl.push({heights.size()-1,j});
        }
        for(int j=0; j<heights.size(); j++){
            atl.push({j,heights[0].size()-1});
        }


        while(!atl.empty()){
            int i = atl.front().first;
            int j = atl.front().second;

            atl.pop();
            atli[i][j] = true;


            for(int k=-1;k<2; k++){
                for(int l=-1;l<2;l++){
                    if((k==0||l==0) && i+k >=0 &&i+k<heights.size() && j+l>=0 && j+l<heights[0].size()){
                        if(heights[i+k][j+l]>= heights[i][j] && !atli[i+k][j+l])
                            atl.push({i+k,j+l});
                    }
                }
            }


        }


         for(int j=0; j<heights[0].size(); j++){
            pac.push({0,j});
        }
        for(int j=0; j<heights.size(); j++){
            pac.push({j,0});
        }


        while(!pac.empty()){
            int i = pac.front().first;
            int j = pac.front().second;

            pac.pop();
            paci[i][j] = true;


            for(int k=-1;k<2; k++){
                for(int l=-1;l<2;l++){
                    if((k==0||l==0) && i+k >=0 &&i+k<heights.size() && j+l>=0 && j+l<heights[0].size()){
                        if(heights[i+k][j+l]>= heights[i][j]&& !paci[i+k][j+l])
                            pac.push({i+k,j+l});
                    }
                }
            }



        }


        vector<vector<int>> ans;

        for(int i=0; i<heights.size(); i++)
            for(int j=0; j<heights[0].size(); j++){
                if(paci[i][j] && atli[i][j])
                    ans.push_back({i,j});
            }

            return ans;
    }
};
