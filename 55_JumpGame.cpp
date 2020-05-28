//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodIndexPosition = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastGoodIndexPosition) {
                lastGoodIndexPosition = i;
            }
        }
        return lastGoodIndexPosition == 0;
    }
};