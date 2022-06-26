int LongestSubsetWithZeroSum(vector < int > arr) {
    int n = arr.size();
    int sum = 0;
    map<int, int> M;
    M[0] = -1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        if(M.find(sum) != M.end()) ans = max(ans, i - M[sum]);
        else M[sum] = i;
    }
    return ans;
}