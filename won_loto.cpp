#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int Nmax = 105;

vector<int> findSum(vector<int> &nums, int S) {
    int n = nums.size();
    unordered_map<int, vector<int>> mySums;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = j; k < n; k++) {
                mySums[nums[i] + nums[j] + nums[k]] = {nums[i], nums[j], nums[k]};
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int k = j; k < n; k++) {
                int remainder = S - nums[i] - nums[j] - nums[k];
                if(mySums.find(remainder) != mySums.end()) {
                    vector<int> otherNums = mySums[remainder];
                    return {nums[i], nums[j], nums[k], otherNums[0], otherNums[1], otherNums[2]};
                }
            }
        }
    }
    return {};
}

int main() {
    int n, S;
    vector<int> nums;
    cin >> n >> S;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        nums.push_back(x);
    }
    vector<int> ans = findSum(nums, S);
    for(int num : ans) {
        cout << num << " ";
    }
    return 0;
}