//
// Created by Chunbin lin on 6/6/20.
//

class MyCalendar {
    vector<pair<int, int>> books;
public:
    bool book(int start, int end) {
        for (pair<int, int> p : books)
            if (max(p.first, start) < min(end, p.second)) return false;
        books.push_back({start, end});
        return true;
    }
};

class MyCalendarTwo {
private:
    vector<pair<int, int>> books;
public:
    MyCalendarTwo() {

    }

    bool book(int start, int end) {
        MyCalendar overlaps;
        for (auto p : books) {
            if (max(p.first, start) < min(end, p.second)) {
                //overlap
                auto p2 = getOverlap(p.first, p.second, start, end);
                if (!overlaps.book(p2.first, p2.second)) return false;
            }
        }
        books.push_back({start, end});
        return true;
    }
    pair<int, int> getOverlap(int s0, int e0, int s1, int e1) {
        return {max(s0, s1), min(e0, e1)};
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */