class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        vector<int>ngrr;
        ngrr.push_back(-1);
        st.push(prices.size()-1);


        for(int i = prices.size()-2; i>=0; i--){
            while(!st.empty()&& prices[st.top()] < prices[i])
                st.pop();
            if(st.empty()){
                st.push(i);
                ngrr.push_back(-1);    
            }
            else ngrr.push_back(prices[st.top()]-prices[i]);    
        }

        int a = INT_MIN;
        for(int i=0; i<ngrr.size(); i++)
            a = max(a,ngrr[i]);
        if(a<0) return 0;
        return a;



    }
};
