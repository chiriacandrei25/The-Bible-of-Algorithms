class Solution {
public:
    bool isPalindrome(string input, int left, int right) {
        string first = input.substr(left, right - left + 1);
        string second = first;
        reverse(second.begin(), second.end());
        return first == second;
    }
    
	int countPalindromes(string input) {
        int result = 0;
        for (int i = 0; i < input.size(); i++) {
            for (int j = i; j < input.size(); j++) {
                if (isPalindrome(input, i, j)) {
                    result++;
                }
            }
        }
        return result;
    }
};

