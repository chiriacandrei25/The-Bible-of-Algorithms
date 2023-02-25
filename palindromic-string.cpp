bool isPalindrome(string input) {
        int left = 0;
        int right = input.size() - 1;
        while (left < right) {
            if (input[left] != input[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
}
