//
// Created by Chunbin lin on 6/4/20.
//

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            swap(s[i++], s[j--]);
        }

    }
};