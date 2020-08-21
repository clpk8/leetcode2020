//
// Created by Chunbin lin on 8/20/20.
//

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int numChars = typed.size() - name.size();
        if (numChars <0) return false;
        int i = 0, j = 0;
        char prev = '.';
        while (i < name.size() && j < typed.size()) {
            if (name[i] != typed[j]) {
                if (numChars < 0) return false;
                if (prev!= typed[j]) return false;
                j++;
                numChars--;
            } else {
                prev = name[i];
                i++;
                j++;
            }
        }

        while (j < typed.size()) {
            if (typed[j++] == prev) {
                numChars--;
            } else {
                return false;
            }
        }
        if (i < name.size()) return false;
        return numChars == 0;
    }
};