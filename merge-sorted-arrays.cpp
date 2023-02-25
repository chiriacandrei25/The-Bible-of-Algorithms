vector<int> merge(vector<int>& first, vector<int>& second) {
        vector<int> result;
        int i = 0, j = 0;
        while (i < first.size() && j < second.size()) {
            if (first[i] < second[j]) {
                result.push_back(first[i]);
                i++;
            } else {
                result.push_back(second[j]);
                j++;
            }
        }
        while (i < first.size()) {
            result.push_back(first[i]);
            i++;
        }
        while (j < second.size()) {
            result.push_back(second[j]);
            j++;
        }
        return result;
    
}
