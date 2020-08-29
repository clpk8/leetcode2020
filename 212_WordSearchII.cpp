//
// Created by Chunbin lin on 8/28/20.
//

//Very slow but build on top of word search 1, every word we run a word search.
// Time complexity: O(sum(m*n*4^l))  l is length = word
// Space complexity: O(l)

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for (string word : words) {
            if (exist(board, word)) ans.push_back(word);
        }
        return ans;
    }

private:
    bool exist(vector<vector<char>> &board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (search(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool search(vector<vector<char>> &board, const string& word, int d, int i, int j) {
        //bound cgecj

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[d] != board[i][j])
            return false;

        if (d == word.size() - 1) return true;

        char cur = board[i][j];
        board[i][j] = '#';
        bool found = search(board, word, d + 1, i + 1, j)
                     || search(board, word, d + 1, i - 1, j)
                     || search(board, word, d + 1, i, j + 1)
                     || search(board, word, d + 1, i, j - 1);

        board[i][j] = cur;
        return found;
    }
};


// A lot faster with Trie!!

class TrieNode {
public:
    vector<TrieNode*> nodes;
    const string* word; // point to address of the word, NULL if currend node is not a word
    TrieNode(): nodes(26), word(NULL) {}

    //destructor, important
    ~TrieNode() {
        for (auto node : nodes) delete node;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode root;

        // add all the words into Trie;
        for (const string& word : words) {
            TrieNode* cur = &root;
            for (char c : word) {
                auto& next = cur->nodes[c - 'a'];
                if (!next) next = new TrieNode();
                cur = next;
            }
            //at the end, link the word
            cur->word = &word;
        }

        vector<string> ans;
        //now all words is in trie
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(i, j, board.size(), board[0].size(), board, &root, ans);
            }
        }
        return ans;
    }

private:
    void dfs(int y, int x, int n, int m, vector<vector<char>>& board, TrieNode* node, vector<string>& ans) {
        if (x < 0 || x >= m || y < 0 || y >= n || board[y][x] == '#') return;

        const char cur = board[y][x];
        TrieNode* next = node->nodes[cur - 'a'];

        if (!next) return; //if we don't have this char in our trie, we prune

        if (next->word) {
            // we are at the end of trie, and found a word
            ans.push_back(*next->word);
            //mark word to NULL
            next->word = NULL;
        }

        //dfs
        board[y][x] = '#';
        dfs(y + 1, x, n, m, board, next, ans);
        dfs(y - 1, x, n, m, board, next, ans);
        dfs(y, x + 1, n, m, board, next, ans);
        dfs(y, x - 1, n, m, board, next, ans);
        board[y][x] = cur;
    }
};