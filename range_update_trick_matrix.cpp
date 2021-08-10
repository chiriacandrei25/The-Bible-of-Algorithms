#include <iostream>

using namespace std;

const int Nmax = 1005;

int a[Nmax][Nmax], n, m, s[Nmax][Nmax];

void update(int r1, int c1, int r2, int c2, int val) {
    a[r1][c1] += val;
    a[r1][c2 + 1] -= val;
    a[r2 + 1][c1] -= val;
    a[r2 + 1][c2 + 1] += val;
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Performing the updates
    int noUpdates;
    cin >> noUpdates;
    while(noUpdates--) {
        int r1, c1, r2, c2, val;
        cin >> r1 >> c1 >> r2 >> c2 >> val;
        update(r1, c1, r2, c2, val);
    }

    // Computing the partial sums:
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    // Printing final matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}