class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(string s: tokens){
            if(s!="+" && s!="*" && s!="-" && s!="/"){
                st.push(stoi(s));
            }
            else{
                    if (s =="+"){
                    
                        int a = st.top();st.pop();
                        a = a+ st.top();st.pop();
                        st.push(a);
                    }    else if (s ==  "-"){
                        int a =  st.top(); st.pop();
                        a = st.top() - a;
                        st.pop();
                        st.push(a);}
                    else if (s ==  "*"){
                        int a = st.top();st.pop();
                        a *= st.top(); st.pop();
                        st.push(a);}
                    else if (s ==  "/"){
                        int a = st.top(); st.pop();
                        a = st.top()/a; st.pop();
                        st.push(a);
                    }
                }
                
            }

                   
                   return st.top();
    }
};
