//
// Created by Chunbin lin on 5/21/20.
//

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = map.find(key);
        //check if key exist if not, return -1
        if (it == map.end())
            return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = map.find(key);
        //check if key exist
        if (it != map.end()) {
            //update
            it->second->second = value;
            //update
            cache.splice(cache.begin(), cache, it->second);
            return;
        }

        //second case, key does not exist but max reached
        //now evice
        if (cache.size() == capacity) {
            auto& node = cache.back();
            map.erase(node.first);
            cache.pop_back();
        }

        //insert the new entry and update mapping
        cache.emplace_front(key, value);
        map[key] = cache.begin(); //update pointer
    }
private:
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> map;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */