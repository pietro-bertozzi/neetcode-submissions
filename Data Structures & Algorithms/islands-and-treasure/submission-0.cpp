class Solution {
public:
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!grid[i][j]) q.push({i, j});
            }
        }
        while (!q.empty()) {
            auto node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];
                if (r >= 0 && r < m && c >= 0 && c < n &&
                    grid[r][c] == INT_MAX) {
                    grid[r][c] = grid[row][col] + 1;
                    q.push({r, c});
                }
            }
        }
    }
};