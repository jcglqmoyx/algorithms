#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Node {
    int l, r;
    int l_max, r_max, mx;
    char lc, rc, c;
} tr[N << 2];

void push_up(Node &u, Node &l, Node &r) {
    u.l_max = l.l_max, u.r_max = r.r_max, u.mx = l.mx, u.lc = l.lc, u.rc = r.rc, u.c = l.c;
    if (r.mx > u.mx) u.mx = r.mx, u.c = r.c;
    if (l.rc == r.lc) {
        if (l.mx == l.r - l.l + 1) u.l_max = l.mx + r.l_max;
        if (r.mx == r.r - r.l + 1) u.r_max = l.r_max + r.mx;
        if (l.r_max + r.l_max > u.mx) u.mx = l.r_max + r.l_max, u.c = l.rc;
    }
}

void push_up(int u) {
    push_up(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(string &s, int u, int l, int r) {
    if (l == r) tr[u] = {l, r, 1, 1, 1, s[l], s[l], s[l]};
    else {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(s, u << 1, l, mid), build(s, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void modify(int u, int x, char c) {
    if (tr[u].l == x && tr[u].r == x) tr[u] = {x, x, 1, 1, 1, c, c, c};
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid) modify(u << 1, x, c);
        else modify(u << 1 | 1, x, c);
        push_up(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (r <= mid) return query(u << 1, l, r);
    else if (l > mid) return query(u << 1 | 1, l, r);
    else {
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        Node res{};
        push_up(res, left, right);
        return res;
    }
}

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices) {
        memset(tr, 0, sizeof tr);
        int n = (int) s.size(), m = (int) queryIndices.size();
        build(s, 1, 0, n - 1);
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            char c = queryCharacters[i];
            int idx = queryIndices[i];
            modify(1, idx, c);
            res[i] = query(1, 0, n - 1).mx;
        }
        return res;
    }
};