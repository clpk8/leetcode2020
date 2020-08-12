
//
// Created by Chunbin lin on 8/11/20.
//

class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> store;
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        store[key].push_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        if (!store.count(key)) return "";

        int left = 0, right = store[key].size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (store[key][mid].first > timestamp)
                right = mid;
            else
                left = mid + 1;
        }
        return left > 0 && left <= store[key].size() ? store[key][left-1].second : "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */