int getInd(vector < vector < int >> & mat, int m, int n, int target) {
    if(target < mat[0][0] || target > mat[m - 1][n - 1]) return -1;
    int low = 0, high = m - 1;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(mat[mid][0] <= target) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ans;
}

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    int i = getInd(mat, m, n, target);
    if(i == -1) return false;
    if(binary_search(mat[i].begin(), mat[i].end(), target)) return true;
    return false;
}