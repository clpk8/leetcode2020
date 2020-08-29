//Wrost will be 26 ^ M
// where M is the lenght of the word
// if we have all dot, we need to find 26 times.

class Node{
public:
    vector<Node*> nodes;
    bool isWord;
    Node() {
        isWord = false;
        nodes = vector<Node*>(26, NULL);
    }

    ~Node() {
        for (auto node : nodes) {
            delete node;
        }
    }
};

class WordDictionary {
private:
    Node *root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node *cur = root;
        for (char c : word) {
            if (cur->nodes[c - 'a'] == NULL) {
                cur->nodes[c - 'a'] = new Node();
            }
            cur = cur->nodes[c - 'a'];
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word, root);
    }

    bool search(string word, Node* node) {
        Node *cur = node;
        if (!cur) return false;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '.') {
                for (auto child : cur->nodes) {
                    if (search(word.substr(i+1), child))
                        return true;

                }
                return false;

            } else {
                if (cur->nodes[c - 'a']) {
                    cur = cur->nodes[c - 'a'];
                } else {
                    return false;
                }
            }
        }
        return cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */