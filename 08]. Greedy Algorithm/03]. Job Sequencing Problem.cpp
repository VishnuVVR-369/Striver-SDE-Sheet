#include<bits/stdc++.h>

static bool comp(vector<int> a, vector<int> b) {
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs) {
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comp);
    int sz = jobs[0][0];
    for(int i = 1; i < n; i++) {
        sz = max(sz, jobs[i][0]);
    }
    int ans = 0;
    vector<bool> slot(sz + 1, false);
    for(int i = 0; i < n; i++) {
        for(int j = jobs[i][0]; j > 0; j--) {
            if(slot[j] == false) {
                slot[j] = true;
                ans += jobs[i][1];
                break;
            }
        }
    }
    return ans;
}
