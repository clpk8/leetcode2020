//
// Created by Chunbin lin on 8/12/20.
//
//DP
/*
 *
 * l[i] := number of flips to make S[0] ~ S[i] become all 0s.

r[i] := number of flips to make S[i] ~ S[n – 1] become all 1s.

Try all possible break point, S[0] ~ S[i – 1] are all 0s and S[i] ~ S[n-1] are all 1s.

ans = min{l[i – 1] + r[i]}

Time complexity: O(n)

Space complexity: O(n)

 */

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n = S.size();
        vector<int> l(S.size() + 1); // 1-> 0
        vector<int> r(S.size() + 1); // 0 -> 1
        l[0] = S[0] - '0'; // add first count, if is 0, no flipt needed
        r[n - 1] = '1' - S[n - 1]; // add last, if it is 1, no flip needed
        for (int i = 1; i < S.size(); i++) {
            l[i] = l[i - 1] + S[i] - '0'; //left must be 0's
        }
        for (int i = n - 2; i >= 0; i--) {
            r[i] = r[i + 1] + '1' - S[i]; //right must be 1's
        }
        int ans = r[0];
        for (int i = 1; i <= n; i++) {
            ans = min(ans, l[i - 1] + r[i]);
        }
        return ans;
    }
};