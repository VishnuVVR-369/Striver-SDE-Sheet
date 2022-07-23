#include<bits/stdc++.h>

static bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i].first = start[i];
        arr[i].second = finish[i];
    }
    sort(arr.begin(), arr.end(), comp);
    int end = arr[0].second;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i].first >= end) {
            end = arr[i].second;
            ans++;
        }
    }
    return ans;
}