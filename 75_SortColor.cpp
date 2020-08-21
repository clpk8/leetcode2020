//
// Created by Chunbin lin on 6/11/20.
//

//brute force
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int num1 = 0, num2 = 0, num3 = 0;
        for (int num : nums) {
            if (num == 0) num1++;
            else if (num == 1) num2++;
            else num3++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (num1) {
                nums[i] = 0;
                num1--;
            } else if (num2) {
                nums[i] = 1;
                num2--;
            } else {
                nums[i] = 2;
            }
        }

    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //move 0 to the front, 2 to the back
        if (nums.size() == 0 || nums.size() == 1) return;

        int start = 0, end = nums.size() - 1;
        int index = 0;

        while (index <= end && start < end) {
            if (nums[index] == 0) {
                nums[index] = nums[start];
                nums[start] = 0;
                start++;
                index++;
            } else if (nums[index] == 2) {
                nums[index] = nums[end];
                nums[end] = 2;
                end--;
            } else {
                index++;
            }
        }
    }
};