//
// Created by Chunbin lin on 8/12/20.
//

//function to find longes possible polindrome
// try all possible i and find the longest palindromic string whose center is id or i/i+1
// find the start = the substring, i - (len - 1) / 2 since i is the center
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();

        //get longes possible polindrome
        // starting from center
        auto getLen = [&](int l, int r) {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            return r - l - 1;
        }; // function to get longes palindrome

        int len = 0;
        int start = 0;
        for (int i = 0; i < n; i++) {
            int cur = max(getLen(i, i), getLen(i, i + 1));
            if (cur > len) {
                len = cur;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, len);

    }
};