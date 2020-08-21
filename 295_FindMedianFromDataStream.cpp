//
// Created by Chunbin lin on 6/9/20.
//

class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        if (max_heap.empty() || num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }

        //step 2 balance heaps

        if (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } else if (max_heap.size() - min_heap.size() == 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }

    double findMedian() {
        if (max_heap.size() > min_heap.size()) {
            return (double) (max_heap.top());
        } else {
            return (double (max_heap.top() + min_heap.top())) / 2;
        }
    }

private:
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */


