int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    unordered_set<int> S;
    for(int i = 0; i < n; i++) {
        S.insert(arr[i]);
    }
    int longestSequence = 1;
    for(int i = 0; i < n; i++) {
        if(S.find(arr[i] - 1) != S.end()) continue;
        int currentSequence = 1;
        int val = arr[i];
        while(S.find(val + 1) != S.end()) {
            currentSequence++;
            val++;
        }
        longestSequence = max(longestSequence, currentSequence);
    }
    return longestSequence;
}