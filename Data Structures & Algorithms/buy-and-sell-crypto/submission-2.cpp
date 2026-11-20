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

        // arr = [3, 1, 6, 7, 9]
        int maxVal = 0;
        int minVal = prices[0];
        
        for (int i : prices) {
            maxVal = max(maxVal, i - minVal);
            minVal = min(minVal, i);
        }
        return maxVal;
    }
};
