vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
    int p1 = m - 1, p2 = n - 1;
    int ind = m + n - 1;
    while(p1 >= 0 && p2 >= 0) {
        if(arr1[p1] > arr2[p2]) {
            arr1[ind--] = arr1[p1--];
        }
        else {
            arr1[ind--] = arr2[p2--];
        }
    }
    while(p1 >= 0) {
        arr1[ind--] = arr1[p1--];
    }
    while(p2 >= 0) {
        arr1[ind--] = arr2[p2--];
    }
    return arr1;
}