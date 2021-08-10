#include <iostream>

using namespace std;

const int Nmax = 1005;

int a[Nmax][Nmax], s[Nmax][Nmax], n, m;

int sum(int l1, int c1, int l2, int c2) {
    return s[l2][c2] - s[l1 - 1][c2] - s[l2][c1 - 1] + s[l1 - 1][c1 - 1];
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    // Computing the partial sums:
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    cout << sum(2, 3, 5, 6);

    return 0;
}