class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l <= r) {
            int m = l + (r - l) / 2;
            int time = 0;
            for (int p : piles) time += ceil((double)p / (double)m);

            if (time <= h)
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
