//
// Created by Chunbin lin on 7/5/20.
//

class Solution {
public:
    int hammingDistance(int x, int y) {
        //how many bits are different
        int result = 0;
        while (x > 0 || y > 0) {
            result += (x % 2) ^ (y % 2);
            x >>= 1;
            y >>= 1;
        }
        return result;
    }
};