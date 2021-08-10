#include <iostream>

using namespace std;

int getValue(int n, int x, int y) {
    if(n == 0) {
        return 1;
    }
    int half_len = (1 << (n - 1));
    if(x <= half_len) {
        if(y <= half_len) {
            return getValue(n - 1, x, y);
        }
        return half_len * half_len + getValue(n - 1, x, y - half_len);
    }
    if(y <= half_len) {
        return 2 * half_len * half_len + getValue(n - 1, x - half_len, y);
    }
    return 3 * half_len * half_len + getValue(n - 1, x - half_len, y - half_len);
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << getValue(n, x, y);
    return 0;
}