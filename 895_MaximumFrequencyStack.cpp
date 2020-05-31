//
// Created by Chunbin lin on 5/30/20.
//

class FreqStack {
public:
    FreqStack() {

    }

    void push(int x) {
        auto it = freq.find(x);
        if (it == freq.end()) {
            //not found
            it = freq.emplace(x, 0).first;
        }
        int freq = ++it->second;
        //current frequence is larger
        if (stacks.size() < freq) stacks.push_back({});
        stacks[freq - 1].push(x);
    }

    int pop() {
        int x = stacks.back().top();
        stacks.back().pop();
        if (stacks.back().empty()) {
            stacks.pop_back();
        }
        auto it = freq.find(x);
        if (--it->second == 0) {
            freq.erase(it);
        }
        return x;
    }
private:
    vector<stack<int>>stacks;
    unordered_map<int, int> freq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */