class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        /*

        input : arr = [1,4,3,2]

        will take 3 integer val where odd, even, count = 0;
        will take long long prefix

        for loop -> 0....size-1;
        i = 0....1...2...3

        prefix += sum of each int val in an array
            // 1....5...8... 11
            if prefix sum % 2 ==1
             1.....1...0....1
                cnt = cnt + (even + 1);
                1.....2.....6
                odd++
                1....2....3
            else
                1....

                cnt = cnt + odd;
                4
                even++;
                1

        return cnt % (1e9 + 7)

         */

        int odd = 0, even = 0;
        long long count = 0, curr = 0;
        for (int i : arr) {
            curr += i;
            if (curr % 2 == 1) {
                odd++;
                count += (1 + even);
            } else {
                even++;
                count += odd;
            }
        }
        return (int)(count % (long)(1e9 + 7));
    }
};