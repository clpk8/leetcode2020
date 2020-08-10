//
// Created by Chunbin lin on 8/9/20.
//

//BFS

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int n = board.size(), m = board[0].size();
        queue<pair<int, int>> q;
        q.emplace(click[0], click[1]);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            int r = p.first, c = p.second;
            if (board[r][c] == 'M') {
                //bomnb, mark it as X and done
                board[r][c] = 'X';
            } else {
                //Now there are 2 logic
                // first find number of mines
                int count = 0;
                for (int i = -1; i < 2; i++) {
                    for (int j = -1; j < 2; j++) {
                        if (i == 0 && j == 0) continue;//self
                        int x = r + i, y = c + j;
                        if (x < 0 || x >= n || y < 0 || y >= m) continue;
                        if (board[x][y] == 'M' || board[x][y] == 'X') count++;
                    }
                }

                if (count > 0) {
                    //record
                    board[r][c] = count + '0';
                } else {
                    //continue to adgent cell
                    for (int i = -1; i < 2; i++) {
                        for (int j = -1; j < 2; j++) {
                            int x = r + i, y = c + j;
                            if (x < 0 || x >= n || y < 0 || y >= m) continue;
                            if (board[x][y] == 'E') {
                                q.emplace(x, y);
                                board[x][y] = 'B'; //mark it so it won't be process again
                            }
                        }
                    }

                }

            }
        }
        return board;
    }
};