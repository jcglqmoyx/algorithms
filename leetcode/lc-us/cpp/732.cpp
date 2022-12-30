#include <bits/stdc++.h>

using namespace std;

class MyCalendarThree {
    map<int, int> M;
public:
    MyCalendarThree() {
    }

    int book(int start, int end) {
        M[start]++, M[end]--;
        int res = 0;
        int x = 0;
        for (auto[_, v]: M) {
            x += v;
            res = max(res, x);
        }
        return res;
    }
};