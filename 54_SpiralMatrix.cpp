//
// Created by Chunbin lin on 8/27/20.
//

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        //0,0 0,1 0,2 1,2 2,2 2,1 2,0 1,0 1,1
        if (matrix.size() == 0) return {};
        int l = 0, t = 0, r = matrix[0].size(), b = matrix.size();
        int total = r * b;
        r--;
        b--;
        int d = 0, row = 0, col = 0;
        vector<int> ans;
        while (ans.size() < total - 1){
            if (d == 0) {
                while (col < r) ans.push_back(matrix[row][col++]);
                t++; //lower a level
            } else if (d == 1) {
                while (row < b) ans.push_back(matrix[row++][col]);
                r--;
            } else if (d == 2) {
                while (col > l) ans.push_back(matrix[row][col--]);
                b--;
            } else {
                while (row > t) ans.push_back(matrix[row--][col]);
                l++;
            }
            d = (d + 1) % 4;
        }
        if (ans.size() != total) ans.push_back(matrix[row][col]);
        return ans;
    }
};