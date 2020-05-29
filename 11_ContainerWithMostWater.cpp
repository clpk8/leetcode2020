//
// Created by Chunbin lin on 5/28/20.
//

//Brute force, TLE
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i; j < height.size(); j++) {
                int minHeight = min(height[i], height[j]);
                maxArea = max(maxArea, minHeight * (j - i));
            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while (i < j) {
            int minHeight = min(height[j], height[j]);
            maxArea = max(maxArea, minHeight * (j - i));
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};