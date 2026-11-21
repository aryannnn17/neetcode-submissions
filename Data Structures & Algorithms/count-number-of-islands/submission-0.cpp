class Solution {
   private:
    void bfs(int n, int m, int row, int col, vector<vector<int>>& vis, vector<vector<char>> grid) {
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            vector<int> dRow = {-1, 0, 1, 0};
            vector<int> dCol = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int nR = r + dRow[i];
                    int nC = c + dCol[i];
                    if (nR >= 0 && nR < n && nC >= 0 && nC < m && !vis[nR][nC] &&
                        grid[nR][nC] == '1') {
                        q.push({nR, nC});
                        vis[nR][nC] = 1;
                    }
                }
            }
        }
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    bfs(n, m, i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};
