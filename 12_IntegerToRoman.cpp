//
// Created by Chunbin lin on 8/27/20.
//

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> map{
                {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
                { 100, "C"}, { 90, "XC"}, { 50, "L"}, { 40, "XL"},
                {  10, "X"}, {  9, "IX"}, {  5, "V"}, {  4, "IV"},
                {   1, "I"}};

        string ans;
        auto it = begin(map);
        while (num) {
            if (num >= it->first) {
                num -= it->first;
                ans += it->second;
            } else {
                it++;
            }
        }
        return ans;
    }
};