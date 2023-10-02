#include <iostream>

using namespace std;

int f[100], expo[100], len = 0;

void primeFact(int n) {
    if(n == 1) {
        len++;
        f[len] = 2;
        expo[len] = 0;
        return;
    }
    int d = 2;
    while(1LL * d * d <= n && n > 1) {
        int k = 0;
        while(n % d == 0) {
            k++;
            n /= d;
        }
        if(k > 0) {
            f[len] = d;
            expo[len] = k;
            len++;
        }
        d++;
    }
    if(n > 1) {
        f[len] = n;
        expo[len] = 1;
        len++;
    }
}

int main()
{
    primeFact(1020);
    for(int i = 0; i < len; i++) {
        cout << f[i] << " " << expo[i] << "\n";
    }
    return 0;
}
