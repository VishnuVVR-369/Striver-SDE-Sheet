void find(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    if(target == 0) {
        ans.push_back(ds);
    }
    if(ind == arr.size()) return;
    for(int i = ind; i < arr.size(); i++) {
        ds.push_back(arr[i]);
        find(i + 1, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k) {
    vector<vector<int>> ans;
    vector<int> ds;
    find(0, k, arr, ds, ans);
    return ans;
}