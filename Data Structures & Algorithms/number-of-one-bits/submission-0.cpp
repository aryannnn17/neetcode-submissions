class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int oneCnt = 0;
        while (n) {
            if (n % 2 == 1) oneCnt++;
            n /= 2;
        }
        return oneCnt;
    }
};
