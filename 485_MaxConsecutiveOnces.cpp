//
// Created by Chunbin lin on 5/18/20.
//

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_onces = 0;
        int current_num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                current_num += 1;
                max_onces = max(max_onces, current_num);
            } else {
                current_num = 0;
            }
        }
        return max_onces;
    }
};