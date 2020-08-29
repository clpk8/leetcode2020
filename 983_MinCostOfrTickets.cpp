//
// Created by Chunbin lin on 8/25/20.
//

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> dayset;
        for (int day : days) {
            dayset.insert(day);
        }
        vector<int> memo(366, -1); // in a year
        return dp(1, costs, memo, dayset);
    }

private:
    int dp(int i, vector<int> costs, vector<int>& memo, unordered_set<int>& dayset) {
        if (i > 365)
            return 0; //we only need to do whtin in a year;

        if (memo[i] != -1) {
            return memo[i]; //reutrn frim memory
        }

        int ans;
        if (dayset.count(i)) {
            ans = min(dp(i+1, costs, memo, dayset) + costs[0], dp(i+7, costs, memo, dayset) + costs[1]);
            ans = min(ans, dp(i + 30, costs, memo, dayset) + costs[2]);
        } else {
            ans = dp(i + 1, costs, memo, dayset);
        }
        memo[i] = ans;
        return ans;
    }
};s