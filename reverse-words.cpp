string joinWithSpace(vector<string> &words) {
        string result = "";
        for (string word : words) {
            result += word + " ";
        }
        result.pop_back();
        return result;
}
    
vector<string> splitBySpace(string &input) {
        stringstream parser(input);
        string word;
        vector<string> words;
        while (parser >> word) {
            words.push_back(word);
        }
        return words;
}
    
string reverseWords(string input) {
        vector<string> words = splitBySpace(input);
        reverse(words.begin(), words.end());
        return joinWithSpace(words);
}
