//
// Created by Chunbin lin on 5/30/20.
//

//slow?

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            add(num);
        }
    }

    int showFirstUnique() {
        return q.size() > 0 ? q.front() : -1;
    }

    void add(int num) {
        if (map.count(num)) {
            //remove from the queue
            auto it = map[num];
            if (it != q.end()) {
                q.erase(it);
                map[num] = q.end();
            }
        } else {
            q.push_back(num);
            auto it = q.end();
            it--;
            map[num] = it;
        }
    }
private:
    list<int> q;
    unordered_map<int, list<int>::iterator> map;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */

//queue but faster for somereason?

class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for (int num : nums) {
            q.push(num);
            counter[num]++;
        }
    }

    int showFirstUnique() {
        while (!q.empty() && counter[q.front()] > 1) {
            q.pop();
        }
        return q.empty() ? -1 : q.front();
    }

    void add(int value) {
        q.push(value);
        counter[value]++;
    }
private:
    queue<int> q;
    unordered_map<int, int> counter;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */