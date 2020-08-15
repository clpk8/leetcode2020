//
// Created by Chunbin lin on 8/14/20.
//

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> counter;
        int res = 0, l = 0;
        for (int r = 0; r < s.size(); r++) {
            counter[s[r]]++;
            while (counter.size() > k) {
                //shrink
                counter[s[l]]--;
                if (counter[s[l]] == 0) counter.erase(s[l]);
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;

    }
};