//
// Created by Chunbin lin on 6/16/20.
//

class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;

        //walk up
        while (i+1 < N && A[i] < A[i+1])
            i++;

        //peak cant be first or last
        if (i == 0 || i == N - 1)
            return false;

        //talk down
        while (i + 1 < N && A[i] > A[i + 1] )
            i++;

        //return true if at the end.
        return i == N - 1;
    }
};