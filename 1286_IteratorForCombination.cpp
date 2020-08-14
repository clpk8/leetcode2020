//
// Created by Chunbin lin on 8/13/20.
//

class CombinationIterator {
private:
    queue<string> q;
public:
    CombinationIterator(string characters, int combinationLength) {
        combinations(characters, 0, "", combinationLength);
    }

    void combinations(string characters, int start, string soFar, int k) {
        if (k == 0) {
            q.push(soFar);
            return;
        }
        for (int i = start; i < characters.size(); i++) {
            combinations(characters, i + 1, soFar + characters[i], k - 1);
        }
    }
    string next() {
        string next = q.front();
        q.pop();
        return next;
    }

    bool hasNext() {
        return !q.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */