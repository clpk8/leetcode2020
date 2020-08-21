//
// Created by Chunbin lin on 5/23/20.
//

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        //find largest start value and smallest end value
        //use two pointers
        //one stay in A, one in B

        int i = 0, j = 0;
        vector<vector<int>> result;
        while (i < A.size() && j < B.size()) {
            int start = max(A[i].front(), B[j].front());
            int end = min(A[i].back(), B[j].back());
            //start <= end, we have overlap
            if (start <= end) result.push_back({start, end});
            if (A[i].back() < B[j].back())
                i++;
            else
                j++;
        }
        return result;
    }
};

