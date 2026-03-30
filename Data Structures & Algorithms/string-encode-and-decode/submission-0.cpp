class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for(int i=0;i<strs.size();i++){
            s += to_string(strs[i].size()) + "s" + strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> sArr;
        while(s.size()>0){
            int in = s.find("s");
            string n = s.substr(0,in);
            int num = stoi(n);
            sArr.push_back(s.substr(in+1,num));            s=s.substr(in+1+num);
        }
        return sArr;
    }
};
