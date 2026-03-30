class Solution {
public:
    void ans(vector<vector<int>>& a, vector<int> & nums, int i, vector<int> st){
        if(i==nums.size()){
            a.push_back(st);
            return;
        }
        ans(a,nums,i+1,st);
        st.push_back(nums[i]);
        ans(a,nums,i+1,st) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> st;
        vector<vector<int>> a;
        ans(a,nums,0,st);

        

        return a; 
    }
};
