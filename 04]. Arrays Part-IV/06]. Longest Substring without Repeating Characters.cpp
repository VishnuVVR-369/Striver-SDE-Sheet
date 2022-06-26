int uniqueSubstrings(string inp) {
    int ans = 0;
    int n = inp.size();
    vector<int> pos(256, -1);
    int left = 0, right = 0;
    while(right < n) {
        if(pos[inp[right]] != -1) left = max(left, pos[inp[right]] + 1);
        pos[inp[right]] = right;
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}