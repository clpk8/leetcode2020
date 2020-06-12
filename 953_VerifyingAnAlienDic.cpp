//
// Created by Chunbin lin on 6/10/20.
//

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int mapping[26];
        for (int i = 0; i < 26; i++) {
            mapping[order[i] - 'a'] = i;
        }

        //now, modifiy original to 0 to 25.
        for (string &w : words) {
            for (char &c : w) {
                c = mapping[c - 'a'];
            }
        }
        return is_sorted(words.begin(), words.end());
    }
};