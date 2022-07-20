string kthPermutation(int n, int k) {
    int fact = 1;
    vector<int> nums;
    for(int i = 1; i <= n; i++) {
        nums.push_back(i);
        fact *= i;
    }
    k--;
    string ans = "";
    fact /= n;
    while(true) {
        ans += to_string(nums[k / fact]);
        nums.erase(nums.begin() + k / fact);
        if(nums.size() == 0) break;
        k = k % fact;
        fact = fact / nums.size();
    }
    return ans;    
}
