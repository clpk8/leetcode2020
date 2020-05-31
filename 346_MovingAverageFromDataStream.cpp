class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        total = 0;
        this->size = size;
        movedOut = 0;
    }

    double next(int val) {
        nums.push_back(val);
        total += val;
        currSize++;

        if (currSize > size) {
            total -= nums[movedOut];
            movedOut++;
        }
        if (nums.size() > size) {
            return total / size;
        } else {
            return total / nums.size();
        }
    }
private:
    double total;
    int movedOut;
    int size;
    int currSize = 0;
    vector<int> nums;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */