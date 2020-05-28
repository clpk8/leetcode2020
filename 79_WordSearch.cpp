//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, int i, int j, int count, string word) {

        //bound check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[i].size() || board[i][j] != word[count]) {
            return false;
        }

        if (count == word.size() - 1) return true;

        char temp = board[i][j];
        board[i][j] = 0;
        bool found = dfs(board, i + 1, j, count + 1, word)
                     || dfs(board, i - 1, j, count + 1, word)
                     || dfs(board, i, j + 1, count + 1, word)
                     || dfs(board, i, j - 1, count + 1, word);

        board[i][j] = temp;
        return found;
    }
};