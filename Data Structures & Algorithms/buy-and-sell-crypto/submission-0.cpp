class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        /*
        int res =0
        for i in 0... size-1
        i = 0..1...
            for i+1.... size - 1
            j = 2
                res = max(res, prices[j] - prices[i])
                // 0...3...4...6...8

        return res
         */

        // arr = [10,3,5,6,1,10]

        int left = 0, right = 1;
        int ans = 0;
        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int curr = prices[right] - prices[left];
                ans = max(curr, ans);
            } else
                left = right;
            right++;
        }
        return ans;
    }
};
