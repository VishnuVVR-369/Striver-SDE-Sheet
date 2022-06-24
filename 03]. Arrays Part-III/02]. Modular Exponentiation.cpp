int modularExponentiation(int x, int n, int m) {
    long long ans = 1;
    while(n) {
        if(n & 1) ans = (ans * x) % m;
        n >>= 1;
        x = (1LL * x * x) % m;
    }
    return ans;
}