int removeDuplicates(vector<int> &arr, int n) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans++;
        int val = arr[i];
        while(i + 1 < n && arr[i + 1] == val) i++;
    }
    return ans;
}