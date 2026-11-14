class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;
        for (int i = 0; i < nums.size(); i++) ans[nums[i]] = i;

        for (int i = 0; i < nums.size(); i++) {
            int d = target - nums[i];
            if (ans.count(d) && ans[d] != i) {
                return {i, ans[d]};
            }
        }
        return {};
    }
};
