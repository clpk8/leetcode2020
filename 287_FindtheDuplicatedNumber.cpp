//
// Created by Chunbin lin on 7/6/20.
//

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        int h = nums[0];

        do {
            t = nums[t];
            h = nums[nums[h]];
        } while (t != h);
        //find the intersection point already

        t = nums[0];
        while (t != h) {
            t = nums[t];
            h = nums[h];
        }
        return h;
    }
};