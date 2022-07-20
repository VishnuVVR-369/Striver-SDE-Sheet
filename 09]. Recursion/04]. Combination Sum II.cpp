#include<bits/stdc++.h>

void find(int ind, int target, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
    if(target == 0) {
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i < arr.size() && target - arr[i] >= 0; i++) {
        if(i != ind && arr[i] == arr[i - 1]) continue;
        ds.push_back(arr[i]);
        find(i + 1, target - arr[i], arr, ds, ans);
        ds.pop_back();
    }
    return;
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    find(0, target, arr, ds, ans);
    return ans;
}