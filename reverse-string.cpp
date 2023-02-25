void swap(string &input, int i, int j) {
        char c = input[i];
        input[i] = input[j];
        input[j] = c;
}
    
string reverse(string input) {
        int left = 0;
        int right = input.size() - 1;
        while (left < right) {
            swap(input, left, right);
            left++;
            right--;
        }
        return input;
}
