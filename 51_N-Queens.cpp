//
// Created by Chunbin lin on 8/13/20.
//

class Solution {
private:
    vector<string> board;
    vector<int> cols;
    vector<int> diag1;
    vector<int> diag2;
    vector<vector<string>> ans;

    // check if we could put it
    bool available(int x, int y, int n) {
        // we going row by row, so check col and diagonal
        // diag1's formula is idx = x + y
        // diag2's formula is x - y + n - 1
        return !cols[x] && !diag1[x+y] && !diag2[x - y + n - 1];
    }

    // update board with 'Q' and '.' and also true or false
    // Like push_back and pop_back for normal backtrack question
    void updateBoard(int x, int y, int n, bool isPut) {
        cols[x] = isPut;
        diag1[x + y] = isPut;
        diag2[x - y + n - 1] = isPut;
        board[y][x] = isPut ? 'Q' : '.'; //if we put, we update with Q
    }

    // try to put the queen on y-th row
    void nqueens(const int n, const int y) {
        if (y == n) {
            //found one sol, add to ans
            //since we going by row, y == n means we complete a board
            ans.push_back(board);
            return;
        }

        //try every column, backtracking
        for (int x = 0; x < n; x++) {
            if (!available(x, y, n)) continue;
            updateBoard(x, y, n, true);
            nqueens(n, y + 1);
            updateBoard(x, y, n, false); //backtrack
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        ans.clear();
        board = vector<string>(n, string(n, '.'));

        cols = vector<int>(n, 0);
        diag1 = vector<int>(2 * n - 1, 0); //size of diaga is 2 * n - 1
        diag2 = vector<int>(2 * n - 1, 0);

        nqueens(n, 0);
        return ans;
    }
};