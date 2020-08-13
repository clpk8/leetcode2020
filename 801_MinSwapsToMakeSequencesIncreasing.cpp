//
// Created by Chunbin lin on 8/12/20.
//

//DFS (O(2^N)) TLE
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        dfs(A, B, 1, 0, ans);
        return ans;
    }
    void dfs(vector<int>& A, vector<int>& B, int i, int c, int& ans) {
        if (c >= ans) {
            return; //we want to find min, don't need to continue
        }

        if (i == A.size()) {
            ans = min(ans, c); //update ans
            return;
        }

        //now still increasing, increase index and cont
        if (A[i] > A[i-1] && B[i] > B[i-1])
            dfs(A, B, i + 1, c, ans);

        //not increasing
        if (A[i] > B[i-1] && B[i] > A[i-1]) {
            //we can swap
            swap(A[i], B[i]);
            dfs(A, B, i + 1, c + 1, ans);
            swap(B[i], A[i]);
        }
    }
};

//DP
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> keep(n, INT_MAX);
        vector<int> swap(n, INT_MAX);

        keep[0] = 0;
        swap[0] = 1;

        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                // it is increasing
                //firsr case, no swapping needed
                keep[i] = keep[i - 1];

                //swapped A[i - 1], B[i - 1], swapA[i],B[i] too
                swap[i] = swap[i - 1] + 1; //one extra swap
            }

            if (B[i] > A[i - 1] && A[i] > B[i - 1]) {
                //A[i-1], B[i-1] weren't swa[[ed
                swap[i] = min(swap[i], keep[i - 1] + 1);

                // Swapped A[i - 1] / B[i - 1], no swap needed for A[i] / B[i]
                keep[i] = min(keep[i], swap[i - 1]);
            }
        }
        return min(keep.back(), swap.back());
    }
};