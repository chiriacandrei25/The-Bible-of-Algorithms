#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long maxRectArea(vector<int> &h) {
    int n = h.size();
    vector<int> Left(n, -1), Right(n, n);
    stack<int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && h[i] < h[st.top()]) {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // st.clear() does not exist but we can clear it another way
    while(!st.empty()) {
        st.pop();
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && h[i] < h[st.top()]) {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    long long ans = 0;
    for(int k = 0; k < n; k++) {
        ans = max(ans, 1LL * h[k] * (Right[k] - Left[k] - 1));
    }

    return ans;
}

int main() {
    int n, x;
    vector<int> h;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        h.push_back(x);
    }
    cout << maxRectArea(h);
    return 0;
}