//
// Created by Chunbin lin on 6/29/20.
//

class NestedIterator {
private:
    int index = 0;
    vector<int> nums;
public:
    void helper(vector<NestedInteger> &nestedList) {
        for (NestedInteger ne : nestedList) {
            if (ne.isInteger()) {
                nums.push_back(ne.getInteger());
            } else {
                helper(ne.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        helper(nestedList);

    }

    int next() {
        return nums[index++];
    }

    bool hasNext() {
        return index < nums.size();
    }
};