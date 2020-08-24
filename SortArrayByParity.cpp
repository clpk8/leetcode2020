//
// Created by Chunbin lin on 8/21/20.
//

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        auto comp = [&](const int &a, const int &b) {
            return a % 2 == 0;
        };

        sort(A.begin(), A.end(), comp);
        return A;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for (int a : A) {
            if (a % 2 == 0) even.push_back(a);
            else odd.push_back(a);
        }
        even.insert(even.end(), odd.begin(), odd.end());
        return even;
    }
};

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = A.size()-1;
        while (i < j) {
            if (A[i] % 2 == 0 && A[j] % 2 != 0) {
                i++;
                j--;
            } else if (A[i] % 2 == 0 && A[j] % 2 == 0) {
                i++;
            } else if (A[i] % 2 != 0 && A[j] % 2 != 0) {
                j--;
            } else {
                swap(A[i++], A[j--]);
            }
        }
        return A;
    }
};