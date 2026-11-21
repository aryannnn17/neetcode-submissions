class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>,int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    q.push({{i, j},0});
                    // vis[i][j] = 1;
                }
            }
        }

        // q = {{0, 2}, {3, 0}, {0,3}}
        int INF = 2147483647;
        vector<int> dR = {-1, 0, 1, 0};
        vector<int> dC = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first; // 0.. 3
            int c = q.front().first.second; // 2... 0
            int s = q.front().second; // 0.. 0
            q.pop(); // {3, 0}, {3, 0}
            s++;
            for (int i = 0; i < 4; i++) {
                int nR = r + dR[i];// 0... 
                int nC = c + dC[i];// 3
                if (nR >= 0 && nC >= 0 && nR < n && nC < m  && grid[nR][nC] == INF) {
                    // vis[nR][nC] = 1;
                    grid[nR][nC] = s; // 1
                    q.push({{nR, nC}, s}); // {0,3}, 1
                }
            }
        }
    }
};
