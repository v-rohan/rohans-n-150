class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = 1;
        while(i<j){
            int s = numbers[i] + numbers[j];
            if(s==target) break;
            if(s>target){
                i++;
                j=i;
            }
            j++;
        }
        vector<int> ans;
        ans.push_back(i+1);
        ans.push_back(j+1); 
        return ans;
    }
};
