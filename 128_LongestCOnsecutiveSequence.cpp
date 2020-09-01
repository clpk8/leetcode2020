//
// Created by Chunbin lin on 8/30/20.
//

//brute force sort
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int longes = 1;
        int temp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] - nums[i-1] == 1) {
                temp++;
                longes = max(longes, temp);
            } else if (nums[i] == nums[i-1]) {
                continue;
            } else {
                temp = 1;
            }
        }
        return longes;
    }
};