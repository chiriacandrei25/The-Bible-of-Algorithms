#include <iostream>

using namespace std;

const int Nmax = 100005;
int fr[Nmax];

int slidingWindow(int *a, int n, int k) {
    int cnt = 0, ans = 0, Right;
    for(Right = 1; Right <= n; Right++) {
        if(++fr[a[Right]] == 1)
            cnt++;
        if(cnt > k)
            break;
    }
    if(cnt <= k)
        return n;
    if(--fr[a[Right]] == 0)
        cnt--;
    Right--; ans = Right;
    for(int Left = 2; Left <= n; Left++) {
        if(--fr[a[Left - 1]] == 0)
            cnt--;
        while(Right < n) {
            Right++;
            if(++fr[a[Right]] == 1)
                cnt++;
            if(cnt > k)
                break;
        }
        if(cnt <=
            k)
            return max(ans, n - Left + 1);
        if(--fr[a[Right]] == 0)
            cnt--;
        Right--;
        ans = max(ans, Right - Left + 1);
    }
}

int main()
{
    int a[Nmax], n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << slidingWindow(a, n, k);
    return 0;
}
