//
// Created by Chunbin lin on 9/1/20.
//

// brute force

class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        //get alll comp

        int largestTime = -1;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    for (int k = 0; k < 4; k++) {
                        if (k!= i && k != j) {
                            int l = 6 - i - j - k;
                            largestTime = max(largestTime, timeComp(A[i],A[j],A[k],A[l]));
                        }
                    }
                }
            }
        }
        if (largestTime == -1) return "";
        int hr = largestTime/60;
        string hr_str = to_string(hr);
        string result;
        if (hr_str.size() == 1)
            hr_str = "0" + hr_str;

        result += hr_str + ":";
        hr = largestTime%60;
        hr_str = to_string(hr);
        if (hr_str.size() == 1)
            hr_str = "0" + hr_str;
        result += hr_str;

        return result;
    }
    int timeComp(int a, int b, int c, int d) {
        int hours = a * 10 + b;
        int min = c * 10 + d;
        if (hours < 24 && min < 60) {
            return hours * 60 + min;
        }
        return -1;
    }
};