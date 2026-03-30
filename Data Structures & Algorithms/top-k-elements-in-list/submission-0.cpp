class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        unordered_map<int, int> ump;
        for(int i=0; i<nums.size(); i++){
            ump[nums[i]] ++; 
        }
        for(auto i: ump){
            
                pq.push({i.second,i.first});

                while(pq.size()>k) pq.pop();
            
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
