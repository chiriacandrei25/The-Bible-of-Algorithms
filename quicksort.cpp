class Solution {
public:
    int partition(vector<int> &nums, int left, int right) {
        int randomIndex = left + rand() % (right - left + 1);
        std::swap(nums[randomIndex], nums[right]);
        int value = nums[right];
        int correctIndex = left;
        for (int i = left; i <= right; ++i) {
            if (nums[i] <= value) {
                std::swap(nums[i], nums[correctIndex]);
                correctIndex++;
            }
        }
        return correctIndex - 1;
    }

    void quickSort(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivot = partition(nums, left, right);
        quickSort(nums, left, pivot - 1);
        quickSort(nums, pivot + 1, right);
    }

    void sort(vector<int> &nums) {
        quickSort(nums, 0, nums.size() - 1);
    }
};
