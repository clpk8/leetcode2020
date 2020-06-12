//
// Created by Chunbin lin on 6/10/20.
//

//keep track of current min and max, if current nums[i] is larget, use it instea;
//only triakc is - - = +
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int current_max = nums[0];
        int current_min = nums[0];
        int final_max = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = current_max;
            current_max = max(max(current_max * nums[i], current_min * nums[i]), nums[i]);
            current_min = min(min(temp * nums[i], current_min * nums[i]), nums[i]);

            final_max = max(final_max, current_max);
        }

        return final_max;
    }
};