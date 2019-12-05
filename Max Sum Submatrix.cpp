#include <iostream>

using namespace std;

const int Nmax = 101;
const int Mmax = 101;

int a[Nmax][Mmax], n, m;
long long UpSum[Nmax][Mmax]; /// UpSum[i][j] = a[1][j] + a[2][j] + ... + a[i][j]
/// UpSum[i][j] = UpSum[i - 1][j] + a[i][j];

long long maxSumSubarray(long long a[], int n) {
    long long ans = a[1], sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }
    return ans;
}

long long maxSumSubmatrix() {
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            UpSum[i][j] = UpSum[i - 1][j] + a[i][j];

    long long v[Mmax]; /// v[i] = a[r1][i] + a[r1+1][i] + ... + a[r2][i]
    long long ans = a[1][1];
    for(int r1 = 1; r1 <= n; r1++)
        for(int r2 = r1; r2 <= n; r2++) {
            for(int i = 1; i <= m; i++)
                v[i] = UpSum[r2][i] - UpSum[r1 - 1][i];
            ans = max(ans, maxSumSubarray(v, m));
        }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << maxSumSubmatrix();
    return 0;
}
