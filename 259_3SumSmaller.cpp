//
// Created by Chunbin lin on 8/27/20.
//

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int t) {

        int n = nums.size();
        int total = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] >= t)
                    k--;
                else {
                    total += k - j;
                    j++;
                }
            }
        }
        return total;
    }
};