vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];
        while(i + 1 < n && end >= intervals[i + 1][0]) {
            end = max(end, intervals[i + 1][1]);
            i++;
        }
        ans.push_back({start, end});
    }
    return ans;
}