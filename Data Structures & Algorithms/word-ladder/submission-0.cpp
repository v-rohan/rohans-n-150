class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(),wordList.end(),endWord);
        if(it==wordList.end()) return 0;
        unordered_map<string,vector<string>> hash;

        for(int i=0;i<beginWord.size(); i++){
                string k = beginWord.substr(0,i) + "*" + beginWord.substr(i+1);
                hash[k].push_back(beginWord);
            }

        for(string s: wordList){
            for(int i=0;i<s.size(); i++){
                string k = s.substr(0,i) + "*" + s.substr(i+1);
                hash[k].push_back(s);
            }
        }

        unordered_map<string,vector<string>> adj;
        unordered_map<string,bool> vis;



        for(pair<string,vector<string>>p: hash ){
            for(int i=0; i<p.second.size(); i++){
                for(int j=i+1; j<p.second.size(); j++){
                        vis[p.second[i]] = false;
                                                vis[p.second[j]] = false;

                        adj[p.second[i]].push_back(p.second[j]);
                        adj[p.second[j]].push_back(p.second[i]);
                }
            }
        }

        queue<pair<string,int>> qu;

        
        int dis = 0;
        qu.push({beginWord,0});

        while(!qu.empty()){
            int d = qu.front().second;
            string w = qu.front().first;

            qu.pop();
            vis[w] = true;

            if(w == endWord){
                dis = d+1;
                break;
            }

            for(string s: adj[w]){
                if(!vis[s]){
                    qu.push({s,d+1});
                }
            }

        }


        return dis;



    }
};
