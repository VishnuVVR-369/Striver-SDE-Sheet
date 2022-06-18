vector<int> nextPermutation(vector<int> &p, int n) {
    int i = n - 1;
    while(i > 0) {
        if(p[i] > p[i-1]) break;
        i--;
    }
    if(i == 0) {
        reverse(p.begin(), p.end());
        return p;
    }
    i--;
    int j = n - 1;
    while(j > 0) {
        if(p[j] > p[i]) break;
        j--;
    }
    swap(p[i], p[j]);
    reverse(p.begin() + i + 1, p.end());
    return p;
}