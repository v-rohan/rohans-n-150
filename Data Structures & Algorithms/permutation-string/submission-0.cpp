class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int match=0;
        if(s1.size()>s2.size()) return false;
        unordered_map<char,int> hash1;
        for(int i = 0; i<s1.size(); i++)
            hash1[s1[i]]++;

        unordered_map<char,int> hash2;

        int i = 0;
        int j = 0;
        while(j<s2.size()){
            hash2[s2[j]]++;
            if(hash1[s2[j]]==hash2[s2[j]]) match++;
            if(j-i+1 == s1.size()){
                if(match==s1.size()) return true;
                if(hash1[s2[i]]== hash2[s2[i]]) match--;
                hash2[s2[i]]--;
                i++;
                            }


            j++;
        }  

        return false;

    }
};
