//
// Created by Chunbin lin on 6/8/20.
//

class Solution {
public:
    bool isPowerOfTwo(int n) {
        long i = 1;
        while (i < n) {
            i *= 2;
        }
        return i == n;
    }
};