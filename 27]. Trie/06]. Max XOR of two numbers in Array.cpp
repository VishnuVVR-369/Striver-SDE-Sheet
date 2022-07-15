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

int getMaxXOR(Node* root, int num) {
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

int maximumXor(vector<int> A) {
    Node* root = new Node();
    int n = A.size();
    for(int i = 0; i < n; i++) {
        insert(root, A[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, getMaxXOR(root, A[i]));
    }
    return ans;
}