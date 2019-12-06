#include <iostream>

using namespace std;

int maxVal(int v[], int n) {
    int maxVal = v[1];
    for(int i = 2; i <= n; i++)
        maxVal = max(maxVal, v[i]);
    return maxVal;
}

long long sumOfAll(int v[], int n) {
    long long sum = 0;
    for(int i = 1; i <= n; i++)
        sum += v[i];
    return sum;
}

bool isValid(int g[], int n, int k, long long C) {
    long long sum = 0;
    int ridesCnt = 1;
    for(int i = 1; i <= n; i++)
        if(sum + g[i] <= C)
            sum += g[i];
        else {
            ridesCnt++;
            sum = g[i];
        }
    return ridesCnt <= k;
}

long long bSearch(int g[], int n, int k) {
    long long Left = maxVal(g, n), Right = sumOfAll(g, n), ans;
    while(Left <= Right) {
        long long Mid = (Left + Right) / 2;
        if(isValid(g, n, k, Mid)) {
            ans = Mid;
            Right = Mid - 1;
        }
        else
            Left = Mid + 1;
    }
    return ans;
}

int main()
{

    return 0;
}
