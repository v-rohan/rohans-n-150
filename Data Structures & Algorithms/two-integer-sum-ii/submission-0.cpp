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
        ans.push_back(numbers[i]);
        ans.push_back(numbers[j]); 
        return ans;
    }
};
