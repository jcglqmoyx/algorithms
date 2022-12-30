#include <bits/stdc++.h>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {
    }

    bool book(int start, int end) {
        auto p = m.upper_bound(start);
        if (p != m.end() && p->second < end) return false;
        else {
            m[end] = start;
            return true;
        }
    }

private:
    map<int, int> m;
};