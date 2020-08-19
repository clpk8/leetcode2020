//
// Created by Chunbin lin on 8/18/20.
//

class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1) return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        vector<int> result;
        for (int n = 1; n < 10; n++) {
            dfs(N-1, n, K, result);
        }
        return result;
    }
    void dfs(int N, int num, int K, vector<int>& result) {
        if (N == 0) {
            result.push_back(num);
            return;
        }

        vector<int> nextDigits;
        int tail = num % 10;
        nextDigits.push_back(tail + K);
        if (K != 0) nextDigits.push_back(tail - K);
        for (int nextDigit : nextDigits) {
            if (0 <= nextDigit && nextDigit < 10) {
                int newNum = num * 10 + nextDigit;
                dfs(N-1, newNum, K, result);
            }
        }
    }
};