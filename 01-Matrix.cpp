class Solution {
public:
    bool isValid(pair<int, int> cell, int n, int m) {
        if(cell.first < 0 || cell.first >= n || cell.second < 0 || cell.second >= m)
            return false;
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> Q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(matrix[i][j] == 0) {
                    dist[i][j] = 0;
                    Q.push({i, j});
                }
        const int dx[] = {-1, 0, 1,  0};
        const int dy[] = { 0, 1, 0, -1};
        while(!Q.empty()) {
            pair<int, int> node = Q.front();
            Q.pop();
            for(int t = 0; t < 4; t++) {
                pair<int, int> neighbor = {node.first + dx[t], node.second + dy[t]};
                if(isValid(neighbor, n, m) && dist[neighbor.first][neighbor.second] == -1) {
                    dist[neighbor.first][neighbor.second] = dist[node.first][node.second] + 1;
                    Q.push(neighbor);
                }
            }
        }
        return dist;
    }
};
