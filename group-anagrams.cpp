string sorted(string s) {
        sort(s.begin(), s.end());
        return s;
}

vector<vector<string>> groupAnagrams(vector<string> &strings) {
        sort(strings.begin(), strings.end(), [&](string a, string b) {
            return sorted(a) < sorted(b);
        });
        vector<vector<string>> result;
        vector<string> currentGroup;
        for (int i = 0; i < strings.size(); i++) {
            currentGroup.push_back(strings[i]);
            if (i == strings.size() - 1 || sorted(strings[i]) != sorted(strings[i + 1])) {
                result.push_back(currentGroup);
                currentGroup = {};
            }
        }
        return result;
}
