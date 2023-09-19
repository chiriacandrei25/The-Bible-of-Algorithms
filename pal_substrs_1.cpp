class Solution {
public:
    int countPalindromesWithCenter(string input, int left, int right) {
        int result = 0;
        while (0 <= left && right < input.size() &&
                    input[left] == input[right]) {
            result += 1;
            left -= 1;
            right += 1;
        }
        return result;
    }
	int countPalindromes(string input) {
        int result = 0;
        for (int i = 0; i < input.size(); i++) {
            result += countPalindromesWithCenter(input, i, i);
            result += countPalindromesWithCenter(input, i, i + 1);
        }
        return result;
    }
};
