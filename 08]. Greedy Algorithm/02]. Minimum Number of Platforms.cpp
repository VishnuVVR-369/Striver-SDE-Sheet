int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at + n);
    sort(dt, dt + n);
    int ans = 1, cnt = 1;
    int i = 1, j = 0;
    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            cnt++;
            i++;
        }
        else {
            cnt--;
            j++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}