#include <iostream>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n;
int b[Nmax]; // used in mergeArrays

void mergeArrays(int left, int mid, int right) {
    int i = left, j = mid + 1, p = 1;
    while(i <= mid && j <= right) {
        if(a[i] <= a[j]) {
            b[p++] = a[i++];
        }
        else {
            b[p++] = a[j++];
        }
    }
    while(i <= mid) {
        b[p++] = a[i++];
    }
    while(j <= right) {
        b[p++] = a[j++];
    }
    for(i = left; i <= right; i++) {
        a[i] = b[i - left + 1];
    }
}

void mergeSort(int left, int right) {
    if(left == right) {
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    mergeArrays(left, mid, right);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    mergeSort(1, n);

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    cout << "\n";

    return 0;
}