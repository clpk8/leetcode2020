//
// Created by Chunbin lin on 8/29/20.
//

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int len = 0, ans = 0, n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 ){
                nums[i] = -1;
            } else if (nums[i] > 0) {
                nums[i] = 1;
            }
        }

        int product = 1;
        for (int i = 0, j = 0; i < n; i++) {
            product *= nums[i];
            if (product == 0) {
                j = i + 1;
                product = 1;
                continue;
            }
            if (product > 0) {
                ans = max(ans, i - j + 1);
            }
        }

        //backward
        product = 1;
        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            product *= nums[i];
            if (product == 0) {
                j = i - 1;
                product = 1;
                continue;
            }
            if (product > 0) {
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};