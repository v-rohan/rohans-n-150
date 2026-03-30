class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c: s){
            if(c=='['||c=='('|| c=='{')
                st.push(c);
            else{
                char chk ; 
                switch (c){
                    case ')':
                    chk = '(';
                    break;
                    case ']':
                    chk = '[';
                    break;
                    case '}':
                    chk = '{';
                    break;
                }

                if (st.empty()  || st.top()!=chk) {
                    return false;
                   }
                st.pop();

            }         
        }

        return st.empty();
    }
};
