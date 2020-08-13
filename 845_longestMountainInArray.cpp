//
// Created by Chunbin lin on 8/12/20.
//

class Solution {
public:
    int longestMountain(vector<int>& A) {
        vector<int> inc(A.size());
        vector<int> dec(A.size());

        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1])
                inc[i] = inc[i-1] + 1;
        }
        for (int i = A.size() - 2; i >= 0; i--) {
            if (A[i] > A[i+1])
                dec[i] = dec[i+1] + 1;
        }

        int ans = 0;
        for (int i = 0; i < A.size(); i++) {
            if (inc[i] && dec[i])
                ans = max(ans, inc[i] + dec[i] + 1);
        }
        return ans;
    }
};

// Better O1 space and one pass
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int inc = 0, dec = 0, ans = 0;
        for (int i = 1; i < A.size(); i++) {
            if (dec && A[i] > A[i - 1] || A[i] == A[i-1])
                dec = inc = 0; //violates the rule, now is 0
            inc += A[i] > A[i-1]; //are we increasing
            dec += A[i] < A[i-1]; //are we decreasing
            if (inc && dec)
                ans = max(ans, inc + dec + 1); //keep track of best
        }
        return ans >= 3 ? ans : 0;
    }
};