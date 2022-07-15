class Node {
public:
    Node* links[2];
    Node() {
        links[0] = links[1] = NULL;
    }
};

void insert(Node* root, int num) {
    Node* node = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(node -> links[bit] == NULL) {
            node -> links[bit] = new Node();
        }
        node = node -> links[bit];
    }
}

int getAns(Node* root, int num) {
    int ans = 0;
    Node* node = root;
    for(int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if(node -> links[bit ^ 1] != NULL) {
            ans |= (1 << i);
            node = node -> links[bit ^ 1];
        }
        else node = node -> links[bit];
    }
    return ans;
}

vector<int> maxXorQueries(vector<int> &nums, vector<vector<int>> &queries) {
    Node* root = new Node();
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<pair<int, pair<int, int>>> oQ;
    int q = queries.size();
    for(int i = 0; i < q; i++) {
        oQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(oQ.begin(), oQ.end());
    vector<int> ans(q, -1);
    int ind = 0;
    for(int i = 0; i < q; i++) {
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int qInd = oQ[i].second.second;
        while(ind < n && nums[ind] <= ai) {
            insert(root, nums[ind]);
            ind++;
        }
        if(ind == 0) ans[qInd] = -1;
        else ans[qInd] = getAns(root, xi);
    }
    return ans;
}