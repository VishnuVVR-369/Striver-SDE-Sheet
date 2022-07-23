#include<bits/stdc++.h>

static bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if(a.first.second == b.first.second) return a.second < b.second;
    return a.first.second < b.first.second;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    int n = start.size();
    vector<pair<pair<int, int>, int>> arr(n);
    for(int i = 0; i < n; i++) {
        arr[i].first.first = start[i];
        arr[i].first.second = end[i];
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end(), comp);
    int currEnd = arr[0].first.second;
    vector<int> ans;
    ans.push_back(arr[0].second);
    for(int i = 1; i < n; i++) {
        if(arr[i].first.first > currEnd) {
            currEnd = arr[i].first.second;
            ans.push_back(arr[i].second);
        }
    }
    return ans;
}