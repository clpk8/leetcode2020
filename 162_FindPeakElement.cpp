//
// Created by Chunbin lin on 5/25/20.
//

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums.front() > nums[1]) return 0;
        if (nums.back() > nums[nums.size() - 2]) return nums.size()-1;
        for (int i = 1; i <= nums.size() - 2; i++) {
            cout << i << endl;
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1])
                return i;
        }
        return -1;
    }
};