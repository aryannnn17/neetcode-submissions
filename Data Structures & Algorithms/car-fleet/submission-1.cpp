class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.rbegin(), v.rend());

        int fleets = 1;
        double prevT = (double)(target - v[0].first) / v[0].second;
        for (const auto& i : v) {
            double currT = (double)(target - i.first) / i.second;
            if (currT > prevT) {
               fleets++;
               prevT = currT;
            }
        }
        return fleets;
    }
};
