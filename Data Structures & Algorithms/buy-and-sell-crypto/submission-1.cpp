class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        vector<int>ngrr;
        ngrr.push_back(-1);
        int in = prices.size()-1;

        for(int i = prices.size()-2; i>=0; i--){
            
            if(prices[in] < prices[i]){
                ngrr.push_back(-1);    
                in  = i;
            }
            else ngrr.push_back(prices[in]-prices[i]);    
        }

        int a = INT_MIN;
        for(int i=0; i<ngrr.size(); i++)
            a = max(a,ngrr[i]);
        if(a<0) return 0;
        return a;



    }
};
