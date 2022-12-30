#include <bits/stdc++.h>

using namespace std;

class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}

    void pushFront(int val) { l.push_front(val), adjust(); }

    void pushMiddle(int val) {
        if (l.size() == r.size() + 1) {
            r.push_front(l.back());
            l.pop_back();
            l.push_back(val);
        } else l.push_back(val);
        adjust();
    }

    void pushBack(int val) { r.push_back(val), adjust(); }

    int popFront() {
        if (l.empty()) return -1;
        int res = l.front();
        l.pop_front();
        adjust();
        return res;
    }

    int popMiddle() {
        if (l.empty()) return -1;
        int res = l.back();
        l.pop_back();
        adjust();
        return res;
    }

    int popBack() {
        if (l.empty()) return -1;
        if (r.empty()) {
            int res = l.back();
            l.pop_back();
            return res;
        }
        int res = r.back();
        r.pop_back();
        adjust();
        return res;
    }

private:
    deque<int> l, r;

    void adjust() {
        while (l.size() > r.size() + 1) {
            r.push_front(l.back());
            l.pop_back();
        }
        while (l.size() < r.size()) {
            l.push_back(r.front());
            r.pop_front();
        }
    }
};