//
// Created by Chunbin lin on 5/18/20.
//

//Brute force, TLE

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = k - 1; i < nums.size(); i++) {
            ans.push_back(*std::max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
        }
        return ans;
    }
};

//slower N * log(k) with bst, but used multieset in c++

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        //multiset is like a bst structure
        multiset<int> window;
        for (int i = 0; i < nums.size(); i++) {
            window.insert(nums[i]);
            //if window size is large enough
            if (i - k + 1 >= 0) {
                //rbegin will get the largesgt val
                ans.push_back(*window.rbegin());
                //use equal range so only erase one element
                //equal_range return a pointer
                window.erase(window.equal_range(nums[i - k + 1]).first);
            }
        }
        return ans;
    }
};


//best N, monotonic queue
class MonotonicQueue {
public:
    //push an elemenbt on the queue will pop all elements smaller than e
    void push(int e) {
        while (!data.empty() && e > data.back()) data.pop_back();
        data.push_back(e);
    }

    //pop the max element
    void pop() {
        data.pop_front();
    }

    //get the front
    int max() const { return data.front(); }
private:
    deque<int> data;

};
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
            //if window size is enough
            if (i - k + 1 >= 0) {
                ans.push_back(q.max());
                //if left of the window is the max, pop them
                if (nums[i - k + 1] == q.max()) q.pop();
            }
        }
        return ans;
    }
};