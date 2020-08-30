//
// Created by Chunbin lin on 8/29/20.
//

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        string s;
        for (int i = 0; i < arr.size(); i++) {
            s += to_string(arr[i]);
        }
        //1, 2, 1, 2, 1, 1, 1, 3
        int size = m * k;
        int l = 0;
        for (int r = 0; r < s.size(); r++) {
            // cout << ";;" << l << " " << r << endl;
            if (r - l + 1 == size) {
                bool found = true;
                //we are at the window
                string str = s.substr(l, m);
                for (int i = 1; i < k; i++) {
                    string second = s.substr(l+ i *m, m);
                    // cout << str << ":" << second<<endl;
                    // cout << second << endl;
                    if (second != str) found = false;
                }
                if (found) return true;
                l++;
            }
            // cout << l << endl;
        }
        return false;

    }
};

//better ON
class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int cur = 0;
        for (int i = 0; i + m < arr.size(); i++) {
            if (arr[i] == arr[i + m])
                cur++;
            else cur = 0;
            if (cur / m == k - 1 && cur % m == 0) return true;
        }
        return false;
    }
};