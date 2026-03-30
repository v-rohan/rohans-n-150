class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int i =0;
        int j = 0;
        int o_c = 0;
        unordered_map<char,int> ump;
        while(j<s.size() && i<=j){
            if(ump.find(s[j]) != ump.end()){
                o_c=max(o_c,j-i);
                ump.erase(s[i]);
                i++;
                j--;
            }
            else{
                ump[s[j]] = 1;
            }
            j++;                
        }

        o_c =max(o_c, (int)s.size()-i);

        return o_c;
    }
};
