class Node {
public:
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
    }
};


class Trie{
    private: Node* root;
    public:

    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node -> links[word[i] - 'a'] == NULL) {
                node -> links[word[i] - 'a'] = new Node();
            }
            node = node -> links[word[i] - 'a'];
            node -> cntPrefix++;
        }
        node -> cntEndWith++;
    }

    int countWordsEqualTo(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node -> links[word[i] - 'a'] == NULL) {
                return 0;
            }
            node = node -> links[word[i] - 'a'];
        }
        return node -> cntEndWith;
    }

    int countWordsStartingWith(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node -> links[word[i] - 'a'] == NULL) {
                return 0;
            }
            node = node -> links[word[i] - 'a'];
        }
        return node -> cntPrefix;
    }

    void erase(string &word){
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            node = node -> links[word[i] - 'a'];
            node -> cntPrefix--;
        }
        node -> cntEndWith--;
    }
};
