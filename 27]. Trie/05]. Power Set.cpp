void find(int ind, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    ans.push_back(ds);
    for(int i = ind; i < arr.size(); i++) {
        ds.push_back(arr[i]);
        find(i + 1, arr, ds, ans);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> pwset(vector<int>v) {
    vector<vector<int>> ans;
    vector<int> ds;
    find(0, v, ds, ans);
    return ans;
}