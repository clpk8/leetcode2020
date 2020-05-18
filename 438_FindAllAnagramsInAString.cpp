//sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int l = p.length();
        vector<int> pos;
        vector<int> vp(26, 0);
        vector<int> vs(26, 0);
        for (char c : p) {
            vp[c - 'a']++;
        }
        for (int i = 0; i < n; i++) {
            if (i >= l) {
                //take out previours
                vs[s[i - l] - 'a']--; 
            }
            vs[s[i] - 'a']++;
            if (vp ==vs) {
                pos.push_back(i + 1 - l);
            }
        }
        return pos;
    }
};