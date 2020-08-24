//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastGoodIndexPosition = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i + nums[i] >= lastGoodIndexPosition) {
                lastGoodIndexPosition = i;s
            }
        }
        return lastGoodIndexPosition == 0;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (i > far) break;
            far = max(far, i + nums[i]);
        }
        return far >= nums.size() - 1;
    }
};
