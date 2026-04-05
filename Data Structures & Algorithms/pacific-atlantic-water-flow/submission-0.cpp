class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));
        queue<pair<int, int>> pacQueue, atlQueue;
        for (int c = 0; c < cols; ++c) {
            pacQueue.push({0, c});
            atlQueue.push({rows - 1, c});
        }
        for (int r = 0; r < rows; ++r) {
            pacQueue.push({r, 0});
            atlQueue.push({r, cols - 1});
        }
        bfs(pacQueue, pac, heights);
        bfs(atlQueue, atl, heights);
        vector<vector<int>> result;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (pac[r][c] && atl[r][c]) {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }

private:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& ocean, vector<vector<int>>& heights) {
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            ocean[r][c] = true;
            for (auto [dr, dc] : directions) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < heights.size() && nc >= 0 &&
                    nc < heights[0].size() && !ocean[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {
                    q.push({nr, nc});
                }
            }
        }
    }
};