class Node {
public:
    Node* links[26];
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};

int distinctSubstring(string &word) {
    Node* root = new Node();
    int n = word.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        Node* node = root;
        for(int j = i; j < n; j++) {
            if(node -> links[word[j] - 'a'] == NULL) {
                node -> links[word[j] - 'a'] = new Node();
                ans++;
            }
            node = node -> links[word[j] - 'a'];
        }
    }
    return ans;
}
