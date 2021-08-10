#include <iostream>
#include <queue>

using namespace std;

const int Nmax = 1005;

bool a[Nmax][Nmax];
int n, m, dist[Nmax][Nmax];

const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

int leeAlgo(pair<int, int> src, pair<int, int> dst) {
    queue<pair<int, int>> Q;
    dist[src.first][src.second] = 1;
    Q.push(src);
    while(!Q.empty()) {
        pair<int, int> cell = Q.front();
        if(cell == dst) {
            return dist[cell.first][cell.second] - 1;
        }
        Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            pair<int, int> neighbor = {cell.first + dx[dir], cell.second + dy[dir]};
            if(a[neighbor.first][neighbor.second] == 1 && 
                dist[neighbor.first][neighbor.second] == 0) {
                    dist[neighbor.first][neighbor.second] = dist[cell.first][cell.second] + 1;
                    Q.push(neighbor);
                }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    pair<int, int> src, dst;
    cin >> src.first >> src.second;
    cin >> dst.first >> dst.second;
    cout << leeAlgo(src, dst);
    return 0;
}