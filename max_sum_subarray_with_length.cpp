#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int Nmax = 100005;

int a[Nmax], n, A, B;

int maxSum(int a[], int n, int A, int B) {
    vector<int> s(n + 1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
    }
    deque<int> dq;
    for(int right = 1; right <= n; right++) {
        if(!dq.empty() && dq.front() < right - B) {
            dq.pop_front();
        }
        if(right >= A) {
            while(!dq.empty() && s[dq.back()] >= s[right - A]) {
                dq.pop_back();
            }
            dq.push_back(right - A);
            ans = max(ans, s[right] - s[dq.front()]);
        }
    }
    return ans;
}

int main() {
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    cout << maxSum(a, n, A, B);
    return 0;
}