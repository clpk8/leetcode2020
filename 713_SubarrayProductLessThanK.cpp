//
// Created by Chunbin lin on 6/10/20.
//

//Sliding window
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) return 0;

        int prod = 1;
        int result = 0;

        int left = 0;
        int right = 0;

        while (right < nums.size()) {
            prod *= nums[right];
            while (prod >= k) {
                prod /= nums[left];
                left++;
            }

            result += right - left + 1;

            right++;
        }

        return result;
    }
};

// same
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int total = 1, l = 0, result = 0;
        for (int r = 0; r < nums.size(); r++) {
            total *=  nums[r];
            while (total >= k) {
                total /= nums[l];
                l++;
            }
            result+= r - l + 1; // all substring will be
        }
        return result;
    }
};