//
// Created by Chunbin lin on 9/1/20.
//

class NumMatrix {
private:

    vector<vector<int>> copy;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        copy = matrix;
    }

    void update(int row, int col, int val) {
        copy[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = 0;
        for (int i = row1; i <= row2; i++) {
            for (int j = col1; j <= col2; j++) {
                total += copy[i][j];
            }
        }
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */

// now everything is ON

class NumMatrix {
private:

    vector<vector<int>> cache;
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        if (matrix.empty()) return;
        cache = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                cache[i][j + 1] = cache[i][j] + matrix[i][j];
            }
        }
    }

    void update(int row, int col, int val) {
        matrix[row][col] = val;

        for (int j = col; j < matrix[0].size(); j++) {
            cache[row][j + 1] = cache[row][j] + matrix[row][j];
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
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */