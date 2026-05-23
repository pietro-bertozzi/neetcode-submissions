class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int best = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int area = 1;
                    queue<pair<int, int>> q;
                    grid[i][j] = '0';
                    q.push({i, j});
                    while (!q.empty()) {
                        pair<int, int> node = q.front();
                        q.pop();
                        int row = node.first, col = node.second;
                        for (int k = 0; k < 4; k++) {
                            int nr = row + directions[k][0];
                            int nc = col + directions[k][1];
                            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                                grid[nr][nc] == 1) {
                                grid[nr][nc] = 0;
                                q.push({nr, nc});
                                area++;
                            }
                        }
                    }
                    best = max(area, best);
                }
            }
        }
        return best;
    }
};