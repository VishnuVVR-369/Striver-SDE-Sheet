// Take care of cases 1 and 2
// arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j]

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> ans(n);
    if(n == 1) return {{1}};
    ans[0] = {1};
    ans[1] = {1, 1};
    if(n == 2) return ans;
    
    for(int i = 2; i < n; i++) {
        vector<long long int> temp(i + 1, 1);
        for(int j = 1; j < i; j++) {
            temp[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans[i] = temp;
    }
    return ans;
}