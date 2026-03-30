class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pP;
        vector<int> poP;
        int p=1;
        for(int i=0; i<nums.size(); i++){
            pP.push_back(p);
            p*=nums[i];
        }
        p=1;
        for(int i=nums.size()-1; i>=0; i--){
            poP.push_back(p);
            p*=nums[i];
        }
        reverse(poP.begin(),poP.end());
        vector<int> n;
        for(int i=0; i<nums.size(); i++){
            n.push_back(pP[i]*poP[i]);
            }
            return n;

    }
};
