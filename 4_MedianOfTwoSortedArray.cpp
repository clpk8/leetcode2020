//
// Created by Chunbin lin on 6/30/20.
//

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> total;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                total.push_back(nums1[i]);
                i++;
            } else {
                total.push_back(nums2[j]);
                j++;
            }
        }
        if (i < nums1.size()) {
            total.insert(total.end(), nums1.begin() + i, nums1.end());
        } else {
            total.insert(total.end(), nums2.begin() + j, nums2.end());
        }

        if (total.size() % 2 == 0) {
            //even
            //1, 2, 3, 4   4 / 2 = 2,
            double a = total[total.size() / 2];
            double b = total[total.size() / 2 - 1];
            return (a + b) / 2;
        } else {
            //odd
            return total[floor(total.size()/2)];
        }
        // for (int k = 0; k < total.size(); k++) {
        //     cout << total[k] << endl;
        // }
    }
};