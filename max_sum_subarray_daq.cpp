#include <iostream>
#include <cmath>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n;

int maxLeftSum(int a[], int left, int mid) {
    int maxS = a[mid], sum = 0;
    for(int l = mid; l >= left; l--) {
        sum += a[l];
        maxS = max(maxS, sum);
    }
    return maxS;
}

int maxRightSum(int a[], int mid, int right) {
    int maxS = a[mid + 1], sum = 0;
    for(int r = mid + 1; r <= right; r++) {
        sum += a[r];
        maxS = max(maxS, sum);
    }
    return maxS;
}

int maxSumSubarray(int a[], int left, int right) {
    if(left == right) {
        return a[left];
    }
    int mid = (left + right) / 2;
    int ans = max(maxSumSubarray(a, left, mid), maxSumSubarray(a, mid + 1, right));
    ans = max(ans, maxLeftSum(a, left, mid) + maxRightSum(a, mid, right));
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << maxSumSubarray(a, 1, n);

    return 0;
}