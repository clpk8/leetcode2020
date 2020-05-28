//
// Created by Chunbin lin on 5/25/20.
//

//run time is O(m * n), space is n
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    //if we can take this coins
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

//small optimization
//run time is O(m * n), space is n
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount + 1);
        dp[0] = 0;
        for (int i = 0; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    //if we can take this coins
                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                } else {
                    break;
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};