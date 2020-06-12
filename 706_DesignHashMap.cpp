//
// Created by Chunbin lin on 6/10/20.
//

//brute force

class MyHashMap {
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map = vector<int> (1000001, -1);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        map[key] = value;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return map[key];
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        map[key] = -1;
    }
private:
    vector<int> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */


class MyHashMap {
private:
    vector<list<pair<int, int>>> map;
    size_t m_size = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        map.resize(m_size);
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &list = map[key % m_size];
        for (auto &val : list) {
            if (val.first == key) {
                val.second = value;
                return;
            }
        }

        list.emplace_back(key, value);
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        const auto &list = map[key % m_size];
        if (list.empty()) {
            return -1;
        }

        for (const auto &val : list) {
            if (val.first == key) {
                return val.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &list = map[key % m_size];
        list.remove_if([key](auto n) { return n.first == key; });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */