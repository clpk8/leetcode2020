//
// Created by Chunbin lin on 6/8/20.
//

//divde by 2 if you can, or subsctract 1
class Solution {
public:
    int brokenCalc(int X, int Y) {
        int ans = 0;
        while (Y > X) {
            ans++;
            if (Y % 2 == 1) Y++;
            else Y /= 2;
        }
        return ans + X - Y;
    }
};