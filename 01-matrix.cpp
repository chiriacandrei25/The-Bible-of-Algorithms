class Solution {
public:
    vector<vector<int>> computeGrid(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    que.push({i, j});
                } else {
                    grid[i][j] = -1;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!que.empty()) {
            auto [x1, y1] = que.front();
            que.pop();
            for (auto [dx, dy] : directions) {
                int x2 = x1 + dx;
                int y2 = y1 + dy;
                if (0 <= x2 && x2 < n && 0 <= y2 && y2 < m && grid[x2][y2] == -1) {
                    grid[x2][y2] = grid[x1][y1] + 1;
                    que.push({x2, y2});
                }
            }
        }

        return grid;
    }
};

