//
// Created by Chunbin lin on 5/22/20.
//

//my own custom solution, TLE
class Point {
public:
    Point(double distance, vector<int> points) {
        this->distance = distance;
        this->points = points;
    }
    double distance;
    vector<int> points;
};

//smaller first
class Compare {
public:
    bool operator() (Point p1, Point p2) {
        return p1.distance < p2.distance;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<Point, vector<Point>, Compare> pq;
        for (auto point : points) {
            Point p(getDistance(point), point);
            pq.push(p);
            //trim
            if (pq.size() > K)
                pq.pop();
        }
        vector<vector<int>> result;
        for (int i = 0; i < K;i++) {
            auto p = pq.top();
            pq.pop();
            result.push_back(p.points);
        }
        return result;
    }
private:
    double getDistance(vector<int> point) {
        return (point[1] * point[1] + point[0] * point[0]);
    }
};
//better but slow

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (auto point : points) {
            pq.push(point);
            if (pq.size() > K)
                pq.pop();
        }

        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
private:
    struct compare {
        bool operator() (vector<int>& p, vector<int>& q) {
            //smaller first
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };
};