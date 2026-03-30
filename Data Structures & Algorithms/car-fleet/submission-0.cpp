class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int, int>> pair;
        for (int i = 0; i < position.size(); i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(),pair.rend());

        double t = (double) ((target-pair[0].first)/pair[0].second);
        int fl = 1;
        for(int i=1;i<pair.size();i++){
            double t2 = (double) ((target-pair[i].first)/pair[i].second);
            if(t2>t){
                t=t2;
                fl++;
            }
        }

        return fl;

    }
};
