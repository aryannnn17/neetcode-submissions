class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        /* if (amount == 0) return 0;
        int cnt = 0;
        int i = coins.size() - 1;
        while (amount > 0 && i >= 0) {
            while (amount < coins[i]) {
                i--;
                if(i < 0)
                    return -1;
            }
            if (amount >= coins[i]) {
                amount -= coins[i];
                cnt++;
            }
        }
        return cnt; */

        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j : coins) {
                if (j <= i) dp[i] = min(dp[i], 1 + dp[i - j]);
            }
        }
        if (dp[amount] > amount) return -1;
        return dp[amount];
    }
};
