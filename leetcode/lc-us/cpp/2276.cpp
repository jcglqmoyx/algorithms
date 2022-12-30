#include <bits/stdc++.h>

using namespace std;

class CountIntervals {
    CountIntervals *left = nullptr, *right = nullptr;
    int l, r;
    int cnt = 0;

public:
    CountIntervals() : l(1), r(1e9) {}

    CountIntervals(int l, int r) : l(l), r(r) {}

    void add(int L, int R) {
        if (cnt == r - l + 1) return;
        if (l >= L && r <= R) {
            cnt = r - l + 1;
            return;
        }
        int mid = (l + r) >> 1;
        if (!left) left = new CountIntervals(l, mid);
        if (!right) right = new CountIntervals(mid + 1, r);
        if (L <= mid) left->add(L, R);
        if (R > mid) right->add(L, R);
        cnt = left->cnt + right->cnt;
    }

    int count() {
        return cnt;
    }
};