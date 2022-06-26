int subarraysXor(vector<int> &arr, int x) {
    int n = arr.size();
    int prefXor = 0;
    int ans = 0;
    unordered_map<int, int> M;
    for(int i = 0; i < n; i++) {
        prefXor ^= arr[i];
        if(prefXor == x) ans++;
        if(M.find(prefXor ^ x) != M.end()) ans += M[prefXor ^ x];
        M[prefXor]++;
    }
    return ans;
}