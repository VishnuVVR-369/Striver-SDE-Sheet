int longestSubSeg(vector<int> &arr , int n, int k) {
    int l = 0, cntZero = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) cntZero++;
        while(cntZero > k) {
            if(arr[l] == 0) cntZero--;
            l++;
        }
        ans = max(ans, i - l + 1);
    }
    return ans;
}