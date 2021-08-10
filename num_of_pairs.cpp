#include <iostream>
#include <unordered_map>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n, S;
unordered_map<int, int> myMap;

int main() {
    int ans = 0;
    cin >> n >> S;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        ans += myMap[S - a[i]];
        myMap[a[i]]++;
    }
    cout << ans;
    return 0;
}