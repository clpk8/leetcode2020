//
// Created by Chunbin lin on 7/5/20.
//

//O2^N
//TLE

class Solution {
private:
    int count = 0;
    void calculate(vector<int> nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S) {
                count++;
            }
        } else {
            calculate(nums, i + 1, sum + nums[i], S);
            calculate(nums, i + 1, sum - nums[i], S);
        }
    }
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        calculate(nums, 0, 0, S);
        return count;
    }
};


