//
// Created by Chunbin lin on 8/12/20.
//

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vals;
        for (int i = 0; i < numRows; i++) {
            if (i == 0) {
                vals.push_back({1});
            } else {
                // index = 2, 3 element
                vector<int> row;
                row.push_back(1);
                vector<int> prevRow = vals[i-1]; //for index 2, we get vals[1]
                for (int j = 1; j < i; j++) {
                    row.push_back(prevRow[j-1] + prevRow[j]);
                }
                row.push_back(1);
                vals.push_back(row);
            }
        }
        return vals;
    }
};