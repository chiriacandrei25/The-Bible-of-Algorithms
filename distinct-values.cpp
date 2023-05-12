int distinctValues(vector<int>& nums) {
        unordered_set<int> values;
        int answer = 0;
        for (int value : nums) {
            if (!values.count(value)) {
                values.insert(value);
                answer++;
            }
        }
        return answer;
}
