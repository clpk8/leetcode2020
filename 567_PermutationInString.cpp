class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1 = s1.size(), len2 = s2.size();
        if (len1 > len2) return false; //no way len2 contian permutation
        
        vector<int> count(26, 0);
        for (int i = 0; i < len1; i++) {
            //add s1
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        
        //check if done
        if (allZeros(count)) return true;
        
        //scan the rest
        for (int i = len1; i < len2; i++) {
            count[s2[i] - 'a']--;//put in new char on the right of window
            count[s2[i - len1] - 'a']++; //left size of window, remove it from count
            if (allZeros(count)) return true;
        }
        
        return false;
        
    }
private:
    bool allZeros(vector<int> count) {
        for (int i : count) {
            if (i != 0) return false;
        }
        return true;
    }
};


//Best
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size(), l2 = s2.size();
        vector<char> c1(26), c2(26);

        for (char c : s1) {
            c1[c - 'a']++;
        }
        for (int i = 0; i < l2; i++) {
            if (i >= l1) {
                //shrink
                --c2[s2[i-l1] - 'a']; //i - l1 will find left
            }
            ++c2[s2[i] - 'a'];
            if (c1 == c2) return true;
        }
        return false;
    }
};