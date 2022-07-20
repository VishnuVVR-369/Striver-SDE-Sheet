bool isPalindrome(string str, int low, int high) {
    while(low < high) {
        if(str[low] != str[high]) return false;
        low++;
        high--;
    }
    return true;
}

void find(int ind, string str, vector<string>&ds, vector<vector<string>>& ans) {
    if(ind == str.size()) {
        ans.push_back(ds);
        return;
    }
    for(int i = ind; i < str.size(); i++) {
        if(isPalindrome(str, ind, i)) {
            ds.push_back(str.substr(ind, i - ind + 1));
            find(i + 1, str, ds, ans);
            ds.pop_back();
        }
    }
    return;
}

vector<vector<string>> partition(string &s)  {
    vector<vector<string>> ans;
    vector<string> ds;
    find(0, s, ds, ans);
    return ans;
}