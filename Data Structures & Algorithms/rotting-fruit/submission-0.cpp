class Solution {
public:
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < m; ++c) {
                if (grid[r][c] == 1) fresh++;
                else if (grid[r][c] == 2) q.push({r, c});
            }
        }
        while (fresh && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; ++i) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for (const auto& dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;
                    if (row >= 0 && row < n && col >= 0 && col < m &&
                        grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh ? -1 : time;
    }
};