class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        vector<int> ngl;
        vector<int> ngr;

        ngl.push_back(-1);
        st.push(0);
        for(int i=1;i<height.size();i++){
            while(!st.empty() && height[st.top()]<=height[i])
                st.pop();
            if(st.empty()) {ngl.push_back(-1);
                        st.push(i);    
}    
            else ngl.push_back(st.top());  
        }

        while(!st.empty())
            st.pop();
        ngr.push_back(-1);

        st.push(height.size()-1);
        for(int i=height.size()-2;i>=0;i--){
            while(!st.empty() && height[st.top()]<=height[i])
                st.pop();
            if(st.empty()){ 
                ngr.push_back(-1);
                st.push(i); 
            }  
            else ngr.push_back(st.top()); 
               
        }
        reverse(ngr.begin(),ngr.end());
        int s = 0;
        for(int i=0; i<height.size(); i++){
            if(ngl[i]==-1 || ngr[i]==-1) continue;

            int m = min(height[ngl[i]],height[ngr[i]]);
            s= s+m-height[i];
            cout << s << endl;
        }
        return s;

    }
};
