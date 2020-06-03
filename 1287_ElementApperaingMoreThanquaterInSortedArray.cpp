//
// Created by Chunbin lin on 5/31/20.
//

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int count = 0;
        int currNum = 0;
        for (int num : arr) {

            if (currNum != num) {
                if (count > (arr.size() / 4)) {
                    return currNum;
                }
                count = 0;
                currNum = num;
            }
            count++;

        }
        if (count > (arr.size() / 4)) {
            return currNum;
        }
        return -1;
    }
};