using LL = long long;

const int MOD = 1e9 + 7;
const int N = 100000;

int cnt;
struct Node {
    int l, r;
    LL val;
    LL mul, add;
} tr[N << 2];

class Fancy {
    void push_down(int u) {
        auto &root = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];

        l.mul = (l.mul * root.mul) % MOD, l.add = (l.add * root.mul + root.add) % MOD;
        r.mul = (r.mul * root.mul) % MOD, r.add = (r.add * root.mul + root.add) % MOD;

        if (l.l == l.r) {
            l.val = (l.val * l.mul + l.add) % MOD;
            l.mul = 1, l.add = 0;
        }
        if (r.l == r.r) {
            r.val = (r.val * r.mul + r.add) % MOD;
            r.mul = 1, r.add = 0;
        }
        root.mul = 1, root.add = 0;
    }

    void build(int u, int l, int r) {
        tr[u] = {l, r, -1, 1, 0};
        if (l != r) {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        }
    }

    void modify(int u, int idx, int val) {
        if (tr[u].l == tr[u].r) tr[u].val = val;
        else {
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (idx <= mid) modify(u << 1, idx, val);
            else modify(u << 1 | 1, idx, val);
        }
    }

    void update(int u, int l, int r, int mul, int add) {
        if (tr[u].l >= l && tr[u].r <= r) {
            auto &root = tr[u];
            root.mul = (root.mul * mul) % MOD, root.add = (root.add * mul) % MOD, root.add = (root.add + add) % MOD;
        } else {
            push_down(u);
            int mid = (tr[u].l + tr[u].r) >> 1;
            if (l <= mid) update(u << 1, l, r, mul, add);
            if (r > mid) update(u << 1 | 1, l, r, mul, add);
        }
    }

    int query(int u, int idx) {
        if (tr[u].l == tr[u].r) {
            tr[u].mul = 1, tr[u].add = 0;
            return (int) tr[u].val;
        }
        push_down(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (idx <= mid) return query(u << 1, idx);
        else return query(u << 1 | 1, idx);
    }

public:
    Fancy() {
        build(1, 0, N - 1);
        cnt = 0;
    }

    void append(int val) {
        modify(1, cnt, val);
        cnt++;
    }

    void addAll(int inc) {
        if (cnt) update(1, 0, cnt - 1, 1, inc);
    }

    void multAll(int m) {
        if (cnt) update(1, 0, cnt - 1, m, 0);
    }

    int getIndex(int idx) {
        if (idx >= cnt) return -1;
        return query(1, idx);
    }
};