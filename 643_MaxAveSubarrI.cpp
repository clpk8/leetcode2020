//
// Created by Chunbin lin on 8/14/20.
//

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int total = 0, l = 0, result = INT_MIN;
        double avg;
        for (int r = 0; r < nums.size(); r++) {
            total += nums[r];
            if (r - l + 1 == k) {
                //check
                result = max(result, total);
                total -= nums[l];
                l++;
            }
        }
        avg = (double)result / k;
        return avg;
    }
};