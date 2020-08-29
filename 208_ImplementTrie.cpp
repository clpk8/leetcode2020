//
// Created by Chunbin lin on 8/28/20.
//

class Node {
public:
    vector<Node*> nodes;
    bool isWord;
    Node() {
        isWord = false;
        nodes = vector<Node*>(26, NULL);
    }

    ~Node(){
        for (auto node: nodes) {
            delete node;
        }
    }
};

class Trie {

private:
    Node *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *cur = root;
        for (char c : word) {
            if (cur->nodes[c - 'a'] == NULL) {
                cur->nodes[c - 'a'] = new Node();
            }
            cur = cur->nodes[c - 'a'];
        }
        //at the end, mark
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *cur = root;
        for (char c : word) {
            if (cur->nodes[c - 'a']) {
                cur = cur->nodes[c - 'a'];
            } else {
                return false;
            }
        }
        return cur->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *cur = root;
        for (char c : prefix) {
            if (cur->nodes[c - 'a']) {
                cur = cur->nodes[c - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */