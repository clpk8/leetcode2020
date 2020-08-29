//
// Created by Chunbin lin on 8/27/20.
//

//DFS connet components
//Trick is find all the edget and set them to G

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();

        for (int y = 0; y < m; y++) {
            dfs(board, 0, y, n, m);
            dfs(board, n - 1, y, n, m);
        }
        for (int x = 0; x < n; x++) {
            dfs(board, x, 0, n, m);
            dfs(board, x, m - 1, n, m);
        }

        //now flip
        map<char, char> v{{'G', 'O'}, {'O', 'X'}, {'X', 'X'}};
        for (int y = 0; y < m; y++) {
            for (int x = 0; x < n; x++) {
                board[y][x] = v[board[y][x]];
            }
        }
    }

private:
    void dfs(vector<vector<char>>& board, int x, int y, int n, int m) {
        if (x < 0 || y < 0 || x >= n || y >= m || board[y][x] != 'O') return;
        board[y][x] = 'G';
        dfs(board, x + 1, y, n, m);
        dfs(board, x - 1, y, n, m);
        dfs(board, x, y + 1, n, m);
        dfs(board, x, y - 1, n, m);
    }
};