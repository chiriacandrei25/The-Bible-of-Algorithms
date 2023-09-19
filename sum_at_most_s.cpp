#include <vector>

using namespace std;

vector<int> longestSubarray(vector<int>& nums, int S) {
    vector<int> answer;
    int maxLen = 0, sum = 0, last = 0;
    for (int first = 0; first < nums.size(); first++) {
        while (last < nums.size() && sum + nums[last] <= S) {
            sum += nums[last];
            if (maxLen < (last - first + 1)) {
                maxLen = last - first + 1;
                answer = {first, last};
            }
            last++;
        }
        sum -= nums[first];
    }
    return answer;
}