vector<int> maxValNumOfOccurrences(vector<int>& nums) {
        int maxVal = nums[0], count = 0;
        for (int val : nums) {
            if (val > maxVal) {
                maxVal = val;
                count = 1;
            } else if (val == maxVal) {
                count++;
            }
        }
        return {maxVal, count};
}
