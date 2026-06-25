class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        for (int i = 0; i < n; i++) {
            if (target < matrix[i][0])
                return 0;
            else if (target >= matrix[i][0] && target <= matrix[i][m - 1]) {
                int low = 0;
                int high = m - 1;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    if (target == matrix[i][mid])
                        return 1;
                    else if (target < matrix[i][mid])
                        high = mid - 1;
                    else
                        low = mid + 1;
                }
            }
        }
        return 0;
    }
};
