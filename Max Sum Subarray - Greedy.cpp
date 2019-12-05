#include <iostream>

using namespace std;

const int Nmax = 10001;

long long maxSumSubarray(int a[], int n) {
    long long sum = 0, ans = a[1];
    for(int i = 1; i <= n; i++) {
        sum += a[i];
        if(sum > ans)
            ans = sum;
        if(sum < 0)
            sum = 0;
    }
    return ans;
}

int main()
{
    int n, a[Nmax];
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << maxSumSubarray(a, n);
    return 0;
}
