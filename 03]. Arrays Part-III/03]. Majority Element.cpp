int findMajorityElement(int arr[], int n) {
    int num = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(cnt == 0) num = arr[i];
        if(num == arr[i]) cnt++;
        else cnt--;
    }
    cnt = 0;
    for(int i = 0; i < n; i++) {
        if(num == arr[i]) cnt++;
    }
    if(cnt > n / 2) return num;
    return -1;
}