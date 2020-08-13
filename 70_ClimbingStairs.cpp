//
// Created by Chunbin lin on 7/3/20.
//

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

//O1 space

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        int dp1 = 1, dp2 = 2;
        for (int i = 3; i <= n; i++) {
            int dp3 = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp3;
        }
        return dp2;
    }
};