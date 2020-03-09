class Solution {
public:
    bool isPartOf(unordered_map<char, int>& a, unordered_map<char, int>& b) {
        for(char c = 'a'; c <= 'z'; c++)
            if(a[c] > b[c])
                return false;
        return true;
    }
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        unordered_map<char, int> totalLetterCounter;
        for(string& b : B) {
            unordered_map<char, int> letterCounter; // initially empty
            for(char c : b)
                letterCounter[c]++;
            for(char c = 'a'; c <= 'z'; c++)
                totalLetterCounter[c] = max(totalLetterCounter[c], letterCounter[c]);
        }
        vector<string> universalWords;
        for(string& a : A) {
            unordered_map<char, int> letterCounter; // initially empty
            for(char c : a)
                letterCounter[c]++;
            if(isPartOf(totalLetterCounter, letterCounter))
                universalWords.push_back(a);
        }
        return universalWords;
    }
};