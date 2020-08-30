//
// Created by Chunbin lin on 8/29/20.
//

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        int l = 0;
        for (int r = 0; r < haystack.size(); r++) {
            if (r - l + 1 == needle.size()) {
                if (haystack.substr(l, needle.size()) == needle) return l;
                l++;
            }
        }
        return -1;
    }
};