class Solution {
public:
    string minWindow(string s, string t) {
        int i=0;
        int j = 0;

        unordered_map<char,int> ump;
                unordered_map<char,int> mp;

        for(char c : t) ump[c]++;
        int d = ump.size();
        int match = 0; 

        string s1 = ""; 

        while(j<s.size()){
            mp[s[j]]++;
            if(mp[s[j]] == ump[s[j]]) match++;
            if(match==d){
                while(match==d){
                    s1 = s1==""?s.substr(i,j-i+1):s1.size()>s.substr(i,j-i+1).size()?s.substr(i,j-i+1):s1;
                    mp[s[i]]--;
                    if(mp[s[i]]!=ump[s[i]] && ump[s[i]]>0)
                        break;    
                    i++;    
                    
                }
               j=++i-1;
               match = 0;
               mp.clear(); 
            }
            j++;
        }

        return s1;
        

    }
};
