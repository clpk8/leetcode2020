class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        unordered_set<char> set({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        for (char &c : s) {
            if (set.count(c)) {
                vowels += c;
                c = '*';
            }
        }
        std::reverse(vowels.begin(), vowels.end());
        int i = 0;
        for (char &c : s) {
            if (c == '*') {
                c = vowels[i++];
            }
        }
        return s;
    }
};