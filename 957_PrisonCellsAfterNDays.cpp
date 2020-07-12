//
// Created by Chunbin lin on 7/4/20.
//

//TLE ON
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        for (int i = 0; i < N; i++) {
            vector<int> copy = cells;
            cells[0] = 0;
            cells[7] = 0;
            for (int j = 1; j < 7; j++) {
                if (copy[j-1] == copy[j+1]) {
                    cells[j] = 1;
                } else {
                    cells[j] = 0;
                }
            }
        }
        return cells;
    }
};
