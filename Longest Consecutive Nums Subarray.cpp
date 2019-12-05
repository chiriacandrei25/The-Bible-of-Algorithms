#include <iostream>

using namespace std;

const int Nmax = 100001;

int a[Nmax], n;
bool fr[Nmax];

int longestConsecNumsSubarray() {
    int ans = 0;
    for(int Left = 1; Left <= n; Left++) {
        for(int i = 1; i <= n; i++)
            fr[i] = false;
        int Min = a[Left], Max = a[Left];
        for(int Right = Left; Right <= n; Right++) {
            if(fr[a[Right]] == true)
                break;
            fr[a[Right]] = true;
            Min = min(Min, a[Right]);
            Max = max(Max, a[Right]);
            if(Right - Left == Max - Min)
                ans = max(ans, Right - Left + 1);
        }
    }
    return ans;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cout << longestConsecNumsSubarray();
    return 0;
}
