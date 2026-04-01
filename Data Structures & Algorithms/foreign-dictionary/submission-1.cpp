class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char,int> indegree;

        for (string w : words) {
            for (char c : w) {
                adj[c] = unordered_set<char>();
                indegree[c] = 0;
            }
        }
        
        for(int i=0; i<words.size()-1; i++){
            string w1 = words[i];
            string w2 = words[i+1];        
            
            int minL = w1.size()<w2.size()?w1.size():w2.size();

            // if(w1.size()>w2.size() && w1.substr(0,minL)==w2.substr(0,minL)) return "";
            
            for(int j=0; j<minL; j++){
                if(w1[j]!=w2[j]){
                    if(!adj[w1[j]].count(w2[j])){
                        adj[w1[j]].insert(w2[j]);
                        indegree[w2[j]]++;
                    }
                    break;
                }
            }

        }


        queue<char>q;
        string ans;

        for(auto &[c,deg]: indegree){
            if(deg == 0)
                q.push(c);
        }


        while(!q.empty()){
            char c = q.front();
            q.pop();
            ans+=c;

            for(char k: adj[c]){
                indegree[k]--;
                if(indegree[k]==0) q.push(k);
            }
        }

        return ans.size() == indegree.size()?ans:"";

    }
};
