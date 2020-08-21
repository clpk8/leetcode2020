//
// Created by Chunbin lin on 8/20/20.
//

//ON^2 brute force
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;
        int total = 0;
        for (int j = 1; j < height.size() - 1; j++) {
            int l = 0;
            for (int i = 0; i <= j ;i++) {
                l = max(l, height[i]);
            }
            int r = 0;
            for (int k = j ; k < height.size(); k++) {
                r = max(r, height[k]);
            }
            total += min(r, l) - height[j];
        }
        return total;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        vector<int> l(height.size()), r(height.size());

        int maxVal = 0;
        for (int i = 0; i < height.size(); i++) {
            maxVal = max(maxVal, height[i]);
            l[i] = maxVal;
        }

        maxVal = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            maxVal = max(maxVal, height[i]);
            r[i] = maxVal;
        }

        int water = 0;
        for (int i = 1; i < height.size() - 1; i++) {
            water += min(r[i], l[i]) - height[i];
        }
        return water;
    }
};

//Best ON time and O1 space two ptr

class Solution {
public:
    int trap(vector<int>& height) {
        const int n = height.size();
        if (n == 0) return 0;
        int l = 0, r = n - 1;
        int max_l = height[l], max_r = height[r];
        int ans = 0;
        while (l < r) {
            if (max_l < max_r) {
                ans += max_l - height[l];
                max_l = max(max_l, height[++l]);
            } else {
                ans += max_r - height[r];
                max_r = max(max_r, height[--r]);
            }
        }
        return ans;
    }
};