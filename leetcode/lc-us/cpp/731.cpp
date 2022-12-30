#include <bits/stdc++.h>

using namespace std;

class MyCalendarTwo {
    map<int, int> m;
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        m[start]++, m[end]--;
        int sum = 0;
        for (auto[k, v]: m) {
            sum += v;
            if (sum >= 3) {
                m[start]--, m[end]++;
                return false;
            }
        }
        return true;
    }
};