//
// Created by Chunbin lin on 5/28/20.
//

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            //since it is sorted, if number is greater than 0,
            //numbers after it will be also greater than 09
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int val = nums[i] + nums[l] + nums[r];
                if (val == 0) {
                    result.push_back({nums[i], nums[l++], nums[r--]});
                    //some number might appear multiple time
                    while (l < r && nums[l] == nums[l - 1]) ++l;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                } else if (val < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return result;
    }
};