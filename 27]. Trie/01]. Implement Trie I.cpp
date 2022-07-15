class Node {
public:
    Node* links[26];
    bool flag;
    Node() {
        for(int i = 0; i < 26; i++) {
            links[i] = NULL;
        }
        flag = false;
    }
};


class Trie {
private:
    Node* root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->links[word[i] - 'a'] == NULL) {
                node -> links[word[i] - 'a'] = new Node();
            }
            node = node -> links[word[i] - 'a'];
        }
        node -> flag = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = root;
        for(int i = 0; i < word.size(); i++) {
            if(node->links[word[i] - 'a'] == NULL) return false;
            node = node -> links[word[i] - 'a'];
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++) {
            if(node->links[prefix[i] - 'a'] == NULL) return false;
            node = node -> links[prefix[i] - 'a'];
        }
        return true;
    }
};