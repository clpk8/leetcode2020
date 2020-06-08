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