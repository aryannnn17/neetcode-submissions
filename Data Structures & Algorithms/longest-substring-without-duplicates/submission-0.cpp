class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int l = 0;
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            while (charSet.find(s[i]) != charSet.end()) {
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[i]);
            ans = max(ans, i - l + 1);
        }
        return ans;
    }
};
