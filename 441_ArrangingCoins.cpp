//
// Created by Chunbin lin on 7/4/20.
//

class Solution {
public:
    int arrangeCoins(int n) {
        if (n == 1) return 1;
        int coins = n;
        int i;
        for (i = 1; i <= n; i++) {
            coins -= i;
            if (coins < 0) {
                break;
            }
        }
        return i - 1;

    }
};

//binary seachn
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        long mid, curr;
        while (left <= right) {
            mid = left + (right - left) / 2;
            curr = mid * (mid + 1) / 2;

            if (curr == n) return (int)mid;

            //binary search
            if (n < curr) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }
        return (int)right;
    }
};