//
// Created by Chunbin lin on 8/20/20.
//

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, returnVal = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int val = nums[i] + nums[j] + nums[k];
                cout << val << endl;
                if (abs(target - val) < abs(diff)) {
                    diff = target - val;
                }
                if (diff == 0) return val;
                if (val < target) j++;
                else k--;
            }
        }
        return target - diff;

    }
};