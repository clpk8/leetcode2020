//
// Created by Chunbin lin on 8/20/20.
//

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size();
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            i++;
            j--;
        }
        return true;
    }
};