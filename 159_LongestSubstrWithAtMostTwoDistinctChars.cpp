class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty()) return 0;
        
        unordered_map<char, int> dict;
        int start = 0, len = 1, count = 0;
        for (int i = 0; i < s.size(); i++) {
            dict[s[i]]++;
            if (dict[s[i]] == 1) {
                //new char
                count++;
                while (count > 2) {
                    //start is the left side of the window
                    dict[s[start]]--;
                    if (dict[s[start]] == 0) count--;
                    start++;
                }
            }
            len = max(len, i - start + 1);
        }
        return len;
    }
};