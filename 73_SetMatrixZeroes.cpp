//
// Created by Chunbin lin on 6/7/20.
//

//time O(mn)
//spaceO(m + n)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector<int> rows(m);
        vector<int> cols(n);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                rows[i] |= !matrix[i][j];
                cols[j] |= !matrix[i][j];
            }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rows[i] || cols[j]) matrix[i][j] = 0;
            }
        }
    }
};

// same
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row, col;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (row.count(i) || col.count(j)) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};


//best O1 space

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isCol = false;
        int R = matrix.size();
        int C = matrix[0].size();

        for (int i = 0; i < R; i++) {
            if (matrix[i][0] == 0) {
                isCol = true;
            }

            for (int j = 1; j < C; j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int j = 0; j < C; j++) {
                matrix[0][j] = 0;
            }
        }

        if (isCol) {
            for (int i = 0; i < R; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};