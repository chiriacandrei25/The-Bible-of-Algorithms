bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomFreq;
        unordered_map<char, int> magazineFreq;
        for (char c : ransomNote) {
            ransomFreq[c]++;
        }
        for (char c : magazine) {
            magazineFreq[c]++;
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (ransomFreq[c] > magazineFreq[c]) {
                return false;
            }
        }
        return true;  
}
