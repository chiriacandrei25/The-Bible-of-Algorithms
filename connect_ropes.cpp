#include <iostream>
#include <queue>
#include <vector>

using namespace std;

long long connectRopes(vector<int> &ropes) {
    long long ans = 0;
    priority_queue<int> pq;
    for(int rope : ropes) {
        pq.push(-rope);
    }
    for(int step = 1; step < ropes.size(); step++) {
        int min1 = -pq.top();
        pq.pop();
        int min2 = -pq.top();
        pq.pop();
        ans += min1 + min2;
        pq.push( -(min1 + min2));
    }
    return ans;
}

int main() {
    int n;
    vector<int> ropes;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ropes.push_back(x);
    }
    cout << connectRopes(ropes);
    return 0;
}