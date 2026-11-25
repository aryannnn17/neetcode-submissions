class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        int zero = 0, one = 0, ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                one++;
            else
                zero++;
            int diff = one - zero;
            if (mp.find(diff) == mp.end()) mp[diff] = i;
            if (one == zero)
                ans = one + zero;
            else
                ans = max(ans, i - mp[diff]);
        }
        return ans;
    }
};
