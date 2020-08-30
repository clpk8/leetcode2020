//
// Created by Chunbin lin on 8/29/20.
//

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //build a dict
        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);

        unordered_map<string, int> steps {{beginWord, 1}}; // counting
        unordered_map<string, vector<string>> parents; // graph, we can get begin given end
        queue<string> q;
        q.push(beginWord);
        vector<vector<string>> ans;

        const int l = beginWord.size();
        int step  = 0;
        bool found = false;

        while (!q.empty() && !found) {
            step++;
            for (int size = q.size(); size > 0; size--) {
                const string p = q.front(); q.pop();
                string w = p; //modify w and keep p unchanged
                for (int i = 0; i < l; i++) {
                    //change everychar
                    const char ch = w[i];
                    for (int j = 'a'; j <= 'z'; j++) {
                        if (j == ch) continue; // we dont need to deal with no change
                        w[i] = j; //make a change and try it out
                        if (w == endWord) {
                            parents[w].push_back(p); //we can get w front change a letter in p
                            found = true;
                        } else {
                            //if not a new word, but antoehr transform
                            // with the same number of steps
                            // we have more sols
                            if (steps.count(w) && step < steps.at(w))
                                parents[w].push_back(p);
                        }

                        if (!dict.count(w)) continue;
                        dict.erase(w);
                        q.push(w);
                        steps[w] = step + 1;
                        parents[w].push_back(p);
                    }
                    //set it back
                    w[i] = ch;
                }

            }
        }
        if (found) {
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, ans); //dfs
        }
        return ans;

    }

private:
    void getPaths(const string& word, const string &beginWord,
                  const unordered_map<string, vector<string>> &parents,
                  vector<string>& curr,
                  vector<vector<string>>& ans) {
        if (word == beginWord) {
            //found
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        for (const string &p : parents.at(word)) {
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }
    }
};