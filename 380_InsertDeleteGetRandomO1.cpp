//
// Created by Chunbin lin on 5/28/20.
//

class RandomizedSet {
private:
    unordered_map<int, int> map; //val : index
    vector<int> vals;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.count(val)) return false;
        map[val] = vals.size();
        vals.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!map.count(val)) return false;
        int index = map[val]; //get the index
        map[vals.back()] = index; //update the back
        swap(vals[index], vals.back()); //swich remove index wiht the last
        map.erase(val); //now remove
        vals.pop_back(); //now move it from the back
        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % vals.size();
        return vals[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */