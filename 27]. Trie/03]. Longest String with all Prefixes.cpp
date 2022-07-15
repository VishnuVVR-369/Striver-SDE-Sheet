class Node {
public:
    Node* links[26];
    bool flag = false;
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};

void insert(Node* root, string str) {
    Node* node = root;
    for(int i = 0; i < str.size(); i++) {
        if(node -> links[str[i] - 'a'] == NULL) {
            node -> links[str[i] - 'a'] = new Node();
        }
        node = node -> links[str[i] - 'a'];
    }
    node -> flag = true;
}

bool find(Node* root, string str) {
    Node* node = root;
    for(int i = 0; i < str.size(); i++) {
        if(node -> links[str[i] - 'a'] == NULL) {
            return false;
        }
        node = node -> links[str[i] - 'a'];
    }
    return (node -> flag == true);
}

string completeString(int n, vector<string> &a){
    Node* root = new Node();
    for(int i = 0; i < n; i++) {
        insert(root, a[i]);
    }
    string ans = "";
    for(int i = 0; i < n; i++) {
        string str = "";
        bool isGood = true;
        for(int j = 0; j < a[i].size(); j++) {
            str += a[i][j];
            if(find(root, str) == false) {
                isGood = false;
                break;
            }
        }
        if(isGood) {
            if(ans.size() < a[i].size()) ans = a[i];
            else if(ans.size() == a[i].size() && ans > a[i]) ans = a[i];
        }
    }
    return ans == "" ? "None" : ans;
}