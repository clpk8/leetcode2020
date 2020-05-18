class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int n = s.length();
        int ans = 0;
        vector<int> idx(128, -1);
        //sliding window i and j
        for (int i = 0, j = 0; j < n; j++) {
            i = max(i, idx[s[j]] + 1);
            ans = max(ans, j - i + 1);
            idx[s[j]] = j;
        }
        return ans;
    }
};


//map
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> index;
        int start = -1;
        int maxLen = 0;
        
        for (int i = 0; i < s.size(); i++) {
            if (index.find(s[i]) != index.end()) {
                //got a new repeating char, either use the old one or a new starrt
                start = max(start, index[s[i]]);
            }
            index[s[i]] = i; //get new indexto
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};