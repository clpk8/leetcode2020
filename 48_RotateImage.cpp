//
// Created by Chunbin lin on 8/28/20.
//

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose and then reverse
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        //reverse
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }

    }
};