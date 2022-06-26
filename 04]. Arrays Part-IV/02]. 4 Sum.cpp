string fourSum(vector<int> arr, int target, int n) {
    unordered_map<int, pair<int, int>> M;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            M[arr[i] + arr[j]] = {i, j};
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int required = target - (arr[i] + arr[j]);
            if(M.find(required) != M.end()) {
                auto ind = M[required];
                int k = ind.first;
                int l = ind.second;
                if(i != k && i != l && j != k && j != l) return "Yes";
            }
        }
    }
    return "No";
}