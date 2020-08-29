//
// Created by Chunbin lin on 8/25/20.
//

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        // abb - >122, acc -> 122
        vector<int> correctCode = encodeString(pattern);
        vector<string> ans;
        for (string word : words) {
            if (correctCode == encodeString(word)) {
                ans.push_back(word);
            }
        }
        return ans;

    }
    vector<int> encodeString(string word) {
        int val = 0;
        vector<int> code;
        unordered_map<char, int> wordMap;
        for (char c : word) {
            if (wordMap.count(c)) {
                code.push_back(wordMap[c]);
            } else {
                code.push_back(val);
                wordMap[c] = val;
                val++;
            }
        }
        return code;
    }

};