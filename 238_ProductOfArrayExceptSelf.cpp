//
// Created by Chunbin lin on 8/28/20.
//

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size());
        vector<int> l(nums.size());

        r[0] = 1;
        l[l.size()-1] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            r[i+1] = r[i] * nums[i];
        }
        cout << endl;
        for (int i = nums.size() -1; i >= 1; i--) {
            l[i-1] = l[i] * nums[i];
        }
        for (int i = 0; i < l.size(); i++) {
            l[i] *= r[i];
        }
        return l;
    }
};

//const space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> r(nums.size());

        r[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            r[i+1] = r[i] * nums[i];
        }

        int l = 1;
        for (int i = nums.size() -1; i >= 0; i--) {
            r[i] = r[i] * l;
            l *= nums[i];
        }
        return r;
    }
};