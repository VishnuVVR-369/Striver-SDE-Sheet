vector<vector<int>> pairSum(vector<int> &arr, int s) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    map<int, int> M;
    for(int i = 0; i < n; i++) {
        int target = s - arr[i];
        int val = M[target];
        while(val--) {
            ans.push_back({target, arr[i]});
        }
        M[arr[i]]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}