class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
/* 
        arr = 2, -1, 1, 2, k =2
        prefix 
        0, 1

         */
        int cnt = 0;
        int sum = 0;
        unordered_map<int, int> prefix;
       prefix[0] = 1;
        for (int n : nums) {
            sum += n;
            cnt += prefix[sum - k];
            prefix[sum]++;
        }
        return cnt;
    }
};