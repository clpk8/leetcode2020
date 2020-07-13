//
// Created by Chunbin lin on 7/11/20.
//

class HitCounter {
private:
    queue<int> hitQueue;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }

    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        hitQueue.push(timestamp);
    }

    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        while (!hitQueue.empty() && timestamp - hitQueue.front() >= 300) {
            hitQueue.pop();
        }
        return hitQueue.size();
    }
};