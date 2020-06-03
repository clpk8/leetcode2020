//
// Created by Chunbin lin on 6/1/20.
//

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> map;
        for (char c : chars) {
            map[c]++;
        }
        int count = 0;
        for (const string &word : words) {
            unordered_map<char, int> temp = map;
            int i = 0;
            for (i; i < word.size(); i++) {
                char c = word[i];
                if (temp.count(c) && temp[c] > 0) {
                    temp[c]--;
                }  else {
                    break;
                }
            }
            if (i == word.size())
                count += word.size();
        }
        return count;
    }
};