class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = INT_MIN;
        stack<int> st;
        vector<int>nsl;
        st.push(0);
        nsl.push_back(-1);

        for(int i=1; i<heights.size(); i++){
            while(!st.empty() && heights[i]<= heights[st.top()]) st.pop();

            if(st.empty()){
                nsl.push_back(-1);
            }

            else{
                nsl.push_back(st.top());
            }
            st.push(i);

        }

        while(!st.empty()) st.pop();

        vector<int>nsr;


        st.push(heights.size()-1);
        nsr.push_back(heights.size());

         for(int i=heights.size()-2; i>=0; i--){
            while(!st.empty() && heights[i]<= heights[st.top()]) st.pop();

            if(st.empty()){
                nsr.push_back(heights.size());
            }

            else{
                nsr.push_back(st.top());
            }
            st.push(i);

        }

        reverse(nsr.begin(),nsr.end());

        for(int i=0;i<heights.size();i++){
            cout << i << " " << nsr[i] << " " << nsl[i] << endl;
            maxArea = max(maxArea, ((nsr[i]-nsl[i]-1)*heights[i]));
        }

        return maxArea;


    }
};
