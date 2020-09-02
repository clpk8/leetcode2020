//
// Created by Chunbin lin on 9/1/20.
//

//cached
class NumMatrix {
    vector<vector<int>> cache;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        cache = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cache[i][j + 1] = cache[i][j] + matrix[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int r = row1; r <= row2; r++) {
            sum += cache[r][col2 + 1] - cache[r][col1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

//same memory but it should be O1 time sum

class NumMatrix {
    vector<vector<int>> cache;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        cache = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cache[i+1][j+1] = cache[i+1][j] + cache[i][j+1] + matrix[i][j] - cache[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return cache[row2+1][col2+1] - cache[row1][col2+1] - cache[row2+1][col1] + cache[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
