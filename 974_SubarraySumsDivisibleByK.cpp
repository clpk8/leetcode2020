//
// Created by Chunbin lin on 7/9/20.
//

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        vector<int> count(k);
        count[0] = 1;
        int prefix = 0, res = 0;
        for (int a : A) {
            prefix = (prefix + a % k + k) % k;
            res += count[prefix]++;
        }
        return res;
    }
};