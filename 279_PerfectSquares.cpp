//
// Created by Chunbin lin on 8/29/20.
//

//time complexity is n^(h/2)
//space is (sqrt(n))^h

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= n; i++) {
            squares.push_back(i * i); //add all squares
        }

        unordered_set<int> q;
        q.insert(n); //find all vals in squares that can construct n
        int level = 0;
        while (!q.empty()) {
            level++;

            unordered_set<int> nextLevel;
            for (int remainder : q) {
                for (int square : squares) {
                    if (remainder == square)
                        return level; //found number of num square
                    else if (remainder < square)
                        break; //no need to con tinue
                    else
                        nextLevel.insert(remainder - square); //continue next level

                }
            }
            swap(q, nextLevel);
        }
        return level;
    }
};