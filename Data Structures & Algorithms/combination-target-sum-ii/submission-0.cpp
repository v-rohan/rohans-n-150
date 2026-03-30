class Solution {
public:
    

        void ans(const vector<int>& nums, vector<vector<int>>& combs, int target,int index, vector<int> st){
        if(target==0){combs.push_back(st);}
        if(target<0) return;
        if(index>=nums.size()) return;
        ans(nums, combs, target, index+1, st);
        st.push_back(nums[index]);
        ans(nums, combs, target-nums[index], index+1, st);
        //ans(nums, combs, target-nums[index], index, st);

    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> an;
        vector<int>st;
        ans(nums,an,target,0, st);
        sort(an.begin(), an.end());
        auto last = unique(an.begin(),an.end());
        an.erase(last, an.end());

        return an;
    }
};
