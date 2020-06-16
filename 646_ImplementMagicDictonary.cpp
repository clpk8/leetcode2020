//
// Created by Chunbin lin on 6/13/20.
//

class MagicDictionary {
private:
    unordered_map<string, unordered_set<char>> map;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        map.clear();
    }

    /** Build a dictionary through a list of words */
    //O(N*M)
    void buildDict(vector<string> dict) {
        for (string& word : dict) {
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                word[i] = '*';
                map[word].insert(c);
                word[i] = c;
            }
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            word[i] = '*';

            if (map.count(word)) {
                const auto& char_set = map[word];
                if (!char_set.count(c) || char_set.size() > 1)
                    return true;
            }
            word[i] = c;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

//Trie
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
class MagicDictionary {
private:
    Trie *trie;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        trie = new Trie();
    }

    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string s : dict) {
            trie->insert(s);
        }
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == word[i]) continue;
                char temp = word[i];
                word[i] = c;
                if (trie->find(word))
                    return true;
                word[i] = temp;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */