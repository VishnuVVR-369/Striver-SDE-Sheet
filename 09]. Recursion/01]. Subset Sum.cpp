vector<int> subsetSum(vector<int> &num) {
    int n = num.size();
    vector<int> ans;
    for(int i = 0; i < (1 << n); i++) {
        int sum = 0, j = i, ind = 0;
        while(j) {
            if(j & 1) sum += num[ind];
            j >>= 1;
            ind++;
        }
        ans.push_back(sum);
    }
    sort(ans.begin(), ans.end());
    return ans;
}