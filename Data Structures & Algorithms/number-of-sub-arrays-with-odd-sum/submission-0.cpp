class Solution {
   public:
    int numOfSubarrays(vector<int>& arr) {
        // inputs : arr

        /*
       
        int count = 0;
        count+1 =
        count = 1
        even + even = even
        even + odd = odd
        odd +odd =  even
        int prefix =
        8 + 5 + 2 = 15
        */

        // arr = [4];

        // Brute - Force solution:


        /* 
         arr = [8, 5, 2,1]
        
        n = 4;
        i = 0 .... 3
        j = i+1 .... 3

        i = 0, j =1 ----> prefix = 13, count = 1
                    j =2 --> prefix = 15, count =1
         */
       long long count = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int prefix = arr[i];
            if (prefix % 2 == 1) count++;
            for (int j = i + 1; j < n; j++) {
                prefix += arr[j];
                if (prefix % 2 == 1) count++;
            }
        }
        return (int) count % 1000000007;
    }
};