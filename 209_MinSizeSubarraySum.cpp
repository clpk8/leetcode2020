//
// Created by Chunbin lin on 8/11/20.
//

//ON
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int left = 0, right = 0, sum = 0, len = nums.size(), res = INT_MAX;
        while (right < len) {
            //Not big enough, keep on adding
            while (sum < s && right < len) {
                sum += nums[right++];
            }
            //now it is enough, we can find min and substructing
            while (sum >= s) {
                res = min(res, right - left);
                sum -= nums[left++];
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};