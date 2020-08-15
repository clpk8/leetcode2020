//
// Created by Chunbin lin on 8/14/20.
//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int l = 0;
        int res = 0;
        for (int r = 0; r < s.size(); r++) {
            map[s[r]]++;
            while (map[s[r]] >= 2) {
                map[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};