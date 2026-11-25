class Solution {
   public:
    bool isAnagram(string s, string t) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (const char& c : s) v1[c - 'a']++;
        for (const char& c : t) v2[c - 'a']++;
        return (v1 == v2);
    }
};
