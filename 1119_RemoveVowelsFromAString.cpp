class Solution {
public:
    string removeVowels(string S) {
        unordered_set<char> vowels({'a', 'e', 'i', 'o', 'u'});
        string result;
        for (int i = 0; i < S.size(); i++) {
            if (!vowels.count(S[i])) {
                result += S[i];
            }
        }
        return result;
    }
};