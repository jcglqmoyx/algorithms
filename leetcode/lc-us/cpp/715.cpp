class RangeModule {
    static const int N = 500000;
    int tr[N], ls[N], rs[N], cnt = 2, lazy0[N], lazy1[N];

    void push_down(int p) {
        if (!ls[p]) ls[p] = cnt++;
        if (!rs[p]) rs[p] = cnt++;
        if (lazy0[p]) {
            lazy0[ls[p]] = 1;
            lazy0[rs[p]] = 1;
            lazy1[ls[p]] = 0;
            lazy1[rs[p]] = 0;
            tr[ls[p]] = 0;
            tr[rs[p]] = 0;
            lazy0[p] = 0;
        }
        if (lazy1[p]) {
            lazy0[ls[p]] = 0;
            lazy0[rs[p]] = 0;
            lazy1[ls[p]] = 1;
            lazy1[rs[p]] = 1;
            tr[ls[p]] = 1;
            tr[rs[p]] = 1;
            lazy1[p] = 0;
        }
    }

    void change(int p, int l, int r, int s, int t, int v) {
        if (s <= l && t >= r) {
            lazy0[p] = v ^ 1;
            lazy1[p] = v;
            tr[p] = v;
        } else {
            int m = (l + r) >> 1;
            push_down(p);
            if (s <= m) change(ls[p], l, m, s, t, v);
            if (t > m) change(rs[p], m + 1, r, s, t, v);
            tr[p] = tr[ls[p]] & tr[rs[p]];
        }
    }

    int query(int p, int l, int r, int s, int t) {
        if (s <= l && r <= t) return tr[p];
        int m = (l + r) >> 1;
        push_down(p);
        int res = 1;
        if (s <= m) res &= query(ls[p], l, m, s, t);
        if (t > m) res &= query(rs[p], m + 1, r, s, t);
        return res;
    }

public:
    RangeModule() {
    }

    void addRange(int left, int right) { change(1, 1, 1e9, left, right - 1, 1); }

    bool queryRange(int left, int right) { return query(1, 1, 1e9, left, right - 1); }

    void removeRange(int left, int right) { change(1, 1, 1e9, left, right - 1, 0); }
};