class Solution {
public:
    void reverse(string &input, int i, int j) {
        while (i < j) {
            swap(input[i], input[j]);
            i++;
            j--;
        }
    }
    
	string reverseWords(string input) {
        reverse(input, 0, input.size() - 1);
        int i = 0;
        while (i < input.size()) {
            int j = i;
            while (j < input.size() && input[j] != ' ') {
                j++;
            }
            reverse(input, i, j - 1);
            i = j + 1;
        }
        return input;
    }
};

