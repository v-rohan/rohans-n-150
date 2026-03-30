class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int in = prices.size()-1;   
        int a = INT_MIN;

        for(int i = prices.size()-2; i>=0; i--){
            
            if(prices[in] < prices[i]){
                in  = i;
            }
            else a=max(a,(prices[in]-prices[i]));    
        }

        
        if(a<0) return 0;
        return a;



    }
};
