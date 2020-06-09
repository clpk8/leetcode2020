//
// Created by Chunbin lin on 6/8/20.
//

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> result(arr.size(), 0);
        int maxVal = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {

            result[i] = maxVal;
            maxVal = max(maxVal, arr[i]);
        }
        return result;
    }
};