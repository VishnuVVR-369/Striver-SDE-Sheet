vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i = 0; i < n; i++) {
        int target = K - arr[i];
        int left = i + 1, right = n - 1;
        while(left < right) {
            if(arr[left] + arr[right] > target) right--;
            else if(arr[left] + arr[right] < target) left++;
            else {
                vector<int> triple(3, 0);
                triple[0] = arr[i];
                triple[1] = arr[left];
                triple[2] = arr[right];
                ans.push_back(triple);
                while(left < right && arr[left] == triple[1]) left++;
                while(left < right && arr[right] == triple[2]) right--;
            }
        }
        while(i + 1 < n && arr[i + 1] == arr[i]) i++;
    }
    return ans;
}