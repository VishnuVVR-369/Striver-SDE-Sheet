int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int lowestPrice = INT_MAX, ans = 0;
    for(int i = 0; i < n; i++) {
        lowestPrice = min(lowestPrice, prices[i]);
        ans = max(ans, prices[i] - lowestPrice);
    }
    return ans;
}