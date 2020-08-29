//
// Created by Chunbin lin on 5/28/20.
//

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for (auto i : nums)
            arr.push_back(to_string(i));
        sort(arr.begin(), arr.end(), [](string &s1, string &s2) { return s1 + s2 > s2 + s1;} );
        string res;
        for (auto s : arr)
            res += s;
        while (res[0] == '0' && res.size() > 1)
            res.erase(0, 1);
        return res;
    }
};

//or this
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [&](string s1, string s2) {
            string a = s1 + s2;
            string b = s2 + s1;
            return a > b;
        };
        vector<string> strs;
        for (int num : nums) {
            strs.push_back(to_string(num));
        }
        sort(strs.begin(), strs.end(), comp);

        if (strs[0] == "0") return "0";
        string result;
        for (string s : strs) {
            result += s;
        }
        return result;
    }
};