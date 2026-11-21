class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 1));
        int cntFresh = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }
        int T = 0;
        int cnt = 0;
        vector<int> nrow = {-1, 0, 1, 0};
        vector<int> ncol = {0, 1, 0, -1};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            T = max(t, T);
            for (int i = 0; i < 4; i++) {
                int nr = r + nrow[i];
                int nc = c + ncol[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && visited[nr][nc] == 1) {
                    q.push({{nr, nc}, t + 1});
                    visited[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        if (cnt != cntFresh) return -1;
        return T;
    }
};
