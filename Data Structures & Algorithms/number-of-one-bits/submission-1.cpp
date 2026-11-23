class Solution {
   public:
    int hammingWeight(uint32_t n) {
        int oneCnt = 0;
        for (int i = 0; i < 32; i++) {
            if ((1 << i & n)) oneCnt++;
        }
        return oneCnt;
    }
};

/// 10111
//// 00001