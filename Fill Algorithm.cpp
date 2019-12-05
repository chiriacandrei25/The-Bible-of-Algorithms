#include <iostream>

using namespace std;

const int Nmax = 1005;

char a[Nmax][Nmax];
bool vis[Nmax][Nmax];
/// (row, col) --> Up: (row - 1, col), Right: (row, col + 1), Down: (row + 1, col), Left: (row, col - 1)
const int dx[] = {-1, 0, 1,  0};
const int dy[] = { 0, 1, 0, -1};

bool isValid(int row, int col, int n, int m) {
    if(row < 1 || row > n || col < 1 || col > m)
        return false;
    if(a[row][col] == '#' || vis[row][col])
        return false;
    return true;
}

void fillAlgo(int row, int col, int n, int m, int& cellsCnt) {
    cellsCnt++;
    vis[row][col] = true;
    for(int dir = 0; dir < 4; dir++)
        if(isValid(row + dx[dir], col + dy[dir], n, m))
            fillAlgo(row + dx[dir], col + dy[dir], n, m, cellsCnt);
}

int main()
{
    int islandsCnt = 0, maxCellsCnt = 0, n ,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(isValid(i, j, n, m)) {
                islandsCnt++;
                int cellsCnt = 0;
                fillAlgo(i, j, n, m, cellsCnt);
                maxCellsCnt = max(maxCellsCnt, cellsCnt);
            }

    cout << islandsCnt << " " << maxCellsCnt << "\n";
    return 0;
}
