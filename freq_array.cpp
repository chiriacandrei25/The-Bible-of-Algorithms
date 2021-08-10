#include <iostream>

using namespace std;

const int ValMax = 100005, Nmax = 100005;

int fr[ValMax], a[Nmax], n;

int main() {
    int cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(fr[a[i]] == 0) {
            cnt++;
        }
        fr[a[i]]++;
    }
    cout << cnt << "\n";
    return 0;
}