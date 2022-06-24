int findDuplicate(vector<int> &arr, int n) {
    for(int i = 0; i < n; i++) {
        if(arr[abs(arr[i])] < 0) return abs(arr[i]);
        else arr[abs(arr[i])] *= -1;
    }
}