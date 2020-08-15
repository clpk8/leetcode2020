class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for (auto c : t) map[c]++;
        int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
        while (end < s.size()) {
            if (map[s[end++]]-- > 0) counter--;
            while (counter == 0) {
                //valid
                if (end - begin < d) {
                    head = begin;
                    d = end - head;
                }
                if (map[s[begin++]]++ == 0) counter++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, d);
    }
};

// similar
class Solution {
public:
    string minWindow(string s, string t) {
        string res = "";
        unordered_map<char, int> counter;
        int l = 0, count = 0, minLen = INT_MAX;
        for (char c : t) counter[c]++;
        for (int r = 0; r < s.size(); r++) {
            if (--counter[s[r]] >= 0) ++count; //if we have this char in dict
            while (count == t.size()) {
                //now we met the requirement
                // find min
                if (minLen > r - l + 1) {
                    //r - l + 1 is the current window size
                    minLen = r - l + 1;
                    res = s.substr(l, minLen); //starting with l, get current window
                }
                //now shtink window, and we need to increase count if s[l] is part of the t
                if (++counter[s[l]] > 0) count--;
                l++;
            }
        }
        return res;
    }
};