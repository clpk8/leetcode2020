//
// Created by Chunbin lin on 6/29/20.
//

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        for (char c : t) {
            if (!count.count(c) || count[c] == 0) {
                return c;
            } else {
                count[c]--;
            }
        }
        return 'a';
    }
};