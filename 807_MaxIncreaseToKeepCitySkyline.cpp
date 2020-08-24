//
// Created by Chunbin lin on 8/21/20.
//

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> row, col;
        for (auto r : grid) {
            int currMax = INT_MIN;
            for (int n : r) {
                currMax = max(currMax, n);
            }
            row.push_back(currMax);
        }
        cout << endl;
        for (int j = 0; j < grid[0].size(); j++) {
            int currMax = INT_MIN;
            for (int i = 0; i < grid.size(); i++) {
                currMax = max(currMax, grid[i][j]);
            }
            col.push_back(currMax);
        }

        int total = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                total += min(row[i], col[j]) - grid[i][j];
            }
        }
        return total;
    }
};