#include <iostream>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n;

int bSearch(int a[], int n, int target) {
    int Left = 1, Right = n, Mid;
    while(Left <= Right) {
        Mid = (Left + Right) / 2;
        if(a[Mid] == target) {
            return Mid;
        }
        if(a[Mid] < target) {
            Left = Mid + 1;
        }
        else {
            Right = Mid - 1;
        }
    }
    return -1;
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int target;
    cin >> target;

    cout << bSearch(a, n, target);

    return 0;
}