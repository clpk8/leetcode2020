//
// Created by Chunbin lin on 6/12/20.
//

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> result(2, -1);
        if (nums.size() == 0) return result;
        //binary search lower bound
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }

        if (nums[left] != target) return result;
        else result[0] = left;

        //binary search upper bound
        right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2 + 1; //make mid biased to the right
            if (nums[mid] > target) right = mid - 1;
            else left = mid;
        }
        result[1] = right;
        return result;
    }
};

//use c++ upperbound and lower bound

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        if (nums.size() == 0) return result;
        //binary search lower bound
        auto left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (left >= nums.size() || nums[left] != target) return result;
        else result[0] = left;

        //binary search upper bound
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        result[1] = right - 1;
        return result;
    }
};