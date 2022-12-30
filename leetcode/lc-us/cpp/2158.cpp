#include <bits/stdc++.h>

using namespace std;

class Solution {
    static constexpr int N = 50010;

    struct Node {
        int l, r;
        int cnt;
        bool flag;
    } tr[N << 2];

    void push_up(int u) {
        tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
    }

    void push_down(int u) {
        auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        if (root.flag) {
            left.cnt = right.cnt = 0;
            left.flag = right.flag = true;
            root.flag = false;
        }
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r};
        if (l == r) tr[u].cnt = 1;
        else {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
            push_up(u);
        }
    }

    int query(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) return tr[u].cnt;
        else {
            push_down(u);
            int mid = (tr[u].l + tr[u].r) >> 1;
            int res = 0;
            if (l <= mid) res += query(u << 1, l, r);
            if (r > mid) res += query(u << 1 | 1, l, r);
            return res;
        }
    }

    void update(int u, int l, int r) {
        if (tr[u].l >= l && tr[u].r <= r) tr[u].cnt = 0, tr[u].flag = true;
        else {
            push_down(u);
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (l <= mid) update(u << 1, l, r);
            if (r > mid) update(u << 1 | 1, l, r);
            push_up(u);
        }
    }

public:
    vector<int> amountPainted(vector<vector<int>> &paint) {
        int n = (int) paint.size();
        build(1, 0, 50000);
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int start = paint[i][0], end = paint[i][1] - 1;
            res[i] = query(1, start, end);
            update(1, start, end);
        }
        return res;
    }
};