pair<int,int> missingAndRepeating(vector<int> &arr, int n) {
    int repeated, missing;
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i]) - 1] > 0) arr[abs(arr[i]) - 1] *= -1;
        else repeated = abs(arr[i]);
    }
    for(int i = 0; i < n; i++) {
        if(arr[i] > 0) missing = i + 1;
    }
    return {missing, repeated};
}