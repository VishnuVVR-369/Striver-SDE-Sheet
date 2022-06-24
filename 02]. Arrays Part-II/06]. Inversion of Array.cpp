long long ans = 0;
void merge(long long *arr, int low, int mid, int high) {
    long long temp[high - low + 1];
    int i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            ans += mid - i + 1;
        }
    }
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    while(j <= high) {
        temp[k++] = arr[j++];
    }
    for(int i = 0; i < high - low + 1; i++) {
        arr[i + low] = temp[i];
    }
}

void mergeSort(long long *arr, int low, int high) {
    if(low >= high) return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n) {
    mergeSort(arr, 0, n - 1);
    return ans;
}