class Solution {
public:
    int maxArea(vector<int>& heights) {
        int m = INT_MIN;
        int i = 0;
        int j = heights.size()-1;

        while(i<j){
            m = max(((j-i)*min(heights[i],heights[j])), m);
            if(heights[i]<heights[j]){
                i++;
            } 
            else{
                j--;
            }
        }

        return m; 
    }
};
