//
// Created by Chunbin lin on 8/20/20.
//

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = S.size();
        while (i < j) {
            if (!isalpha(S[i])) {
                i++;
                continue;
            } else if (!isalpha(S[j])) {
                j--;
                continue;
            } else {
                swap(S[i++], S[j--]);
            }
        }
        return S;
    }
};