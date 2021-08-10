#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n, k;

vector<int> findMins(int a[], int n, int k) {
    deque<int> dq;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        while(!dq.empty() && a[dq.back()] >= a[i]) {
            dq.pop_back();
        }
        if(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        dq.push_back(i);
        if(i >= k) {
            ans.push_back(a[dq.front()]);
        }
    }
    return ans;
}

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> ans = findMins(a, n, k);
    for(int minVal : ans) {
        cout << minVal <<" ";
    }
    return 0;
}