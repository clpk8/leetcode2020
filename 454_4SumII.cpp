//
// Created by Chunbin lin on 8/29/20.
//

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> map;
        for (int a : A) {
            for (int b : B) {
                map[a + b]++;
            }
        }

        int count = 0;
        for (int c : C) {
            for (int d : D) {
                if (map.count(-(c + d))) {
                    count += map[-(c + d)];
                }
            }
        }
        return count;
    }
};