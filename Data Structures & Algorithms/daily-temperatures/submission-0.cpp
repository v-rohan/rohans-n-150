class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ngr;
        stack<int> st;
        for(int i = temperatures.size()-1; i>=0; i--){
            if(st.empty()){
                ngr.push_back(0);
            }
            else{
                while(!st.empty() && temperatures[st.top()]<temperatures[i]) st.pop();
                ngr.push_back(st.empty()?0:st.top()-i);
               }
               st.push(i);
        }
        reverse(ngr.begin(),ngr.end());
        return ngr;
    }
};
