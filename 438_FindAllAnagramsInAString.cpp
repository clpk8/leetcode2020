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
            if (vp == vs) {
                pos.push_back(i + 1 - l);
            }
        }
        return pos;
    }
};


//use Hashmap, much slower cause of the overhead.

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), l = p.size();
        vector<int> ans;
        unordered_map<char, int> vp;
        unordered_map<char, int> vs;
        for (char c : p) ++vp[c];

        for (int i = 0; i < n; i++) {
            if (i >= l) {
                //window size need to shrink
                --vs[s[i - l]]; //i - l will give you the old left side of window
                if (vs[s[i - l]] == 0)
                    vs.erase(s[i - l]);
            }
            //now we can expand right
            ++vs[s[i]];
            if (vs == vp) ans.push_back(i + 1 - l); // i - l is old left side, i - l + 1 is  the left side
        }
        return ans;
    }
};