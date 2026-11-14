class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            mp[sortedS].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto s : mp) ans.push_back(s.second);

        return ans;
    }
};
