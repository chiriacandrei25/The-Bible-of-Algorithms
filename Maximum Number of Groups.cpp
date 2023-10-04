#include <iostream>

using namespace std;

const int Nmax = 100005;

bool isValid(int a[], int n, int k, long long x) {
    long long cnt = 0;
    for(int i = 1; i <= n; i++)
        cnt += min(x, 1LL * a[i]);
    return cnt >= 1LL * x * k;
}

long long sum_of(int a[], int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        sum += a[i];
    return sum;
}

long long bSearch(int a[], int n, int k) {
    long long Left = 0, Right = sum_of(a, n)/k, ans;
    while(Left <= Right) {
        long long Mid = (Left + Right) / 2;
        if(isValid(a, n, k, Mid)) {
            ans = Mid;
            Left = Mid + 1;
        }
        else
            Right = Mid - 1;
    }
    return ans;
}

int main()
{
    int n, k, a[Nmax];
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << bSearch(a, n, k);
    return 0;
}
