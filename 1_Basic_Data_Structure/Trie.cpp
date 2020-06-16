//
// Created by Chunbin lin on 6/13/20.
//

class Node{
public:
    vector<Node*> next;
    bool isWord;
    Node() {
        isWord = false;
        next = vector<Node*>(26, NULL);
    }
};

class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(string s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->next[c - 'a'] == NULL) {
                //create new nodes
                cur->next[c - 'a'] = new Node();
            }
            cur = cur->next[c - 'a'];
        }
        //at the end, mark a word
        cur->isWord = true;
    }

    bool find(string s) {
        Node* cur = root;
        for (char c : s) {
            if (cur->next[c - 'a'] == NULL)
                return false;
            cur = cur->next[c - 'a'];
        }
        return cur->isWord;
    }
};