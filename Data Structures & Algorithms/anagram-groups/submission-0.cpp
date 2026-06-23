class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<int>> mp;
        vector<string> temp = strs;
        for(int i =0;i<strs.size();++i){
            sort(strs[i].begin(),strs[i].end());    
            mp[strs[i]].push_back(i);    
        }

        for(auto& i : mp){
            vector<string> s;
            for(auto& j : i.second)
                s.push_back(temp[j]);
            ans.push_back(s);
        }
        return ans;
    }
};
