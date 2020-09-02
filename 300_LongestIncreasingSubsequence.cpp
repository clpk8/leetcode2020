//
// Created by Chunbin lin on 9/1/20.
//

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size());
        int maxAns = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            int longest = 0;
            int j;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    longest = max(longest, dp[j]);
                }
            }
            dp[i] = longest + 1;
            maxAns = max(maxAns, dp[i]);
        }
        return maxAns;
    }
};