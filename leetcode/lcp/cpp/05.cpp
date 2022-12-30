#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int MOD = 1e9 + 7, N = 50010;

struct Node {
    int l, r;
    int sum;
    int add;
} tr[N << 2];

int L[N], R[N];

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l < r) {
        int mid = (l + r) >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void push_up(int u) {
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % MOD;
}

void push_down(int u) {
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add) {
        left.add += root.add, left.sum = (int) ((left.sum + (LL) root.add * (left.r - left.l + 1)) % MOD);
        right.add += root.add, right.sum = (int) ((right.sum + (LL) root.add * (right.r - right.l + 1)) % MOD);
        root.add = 0;
    }
}

void update(int u, int l, int r, int dt) {
    if (tr[u].l >= l && tr[u].r <= r)
        tr[u].add += dt, tr[u].sum = (int) ((tr[u].sum + (LL) (tr[u].r - tr[u].l + 1) * dt) % MOD);
    else {
        push_down(u);
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) update(u << 1, l, r, dt);
        if (r > mid) update(u << 1 | 1, l, r, dt);
        push_up(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;

    push_down(u);
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = query(u << 1, l, r);
    if (r > mid) res += query(u << 1 | 1, l, r);
    push_up(u);
    return res % MOD;
}

class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>> &leadership, vector<vector<int>> &operations) {
        tot = 0;
        for (auto &e: leadership) {
            g[e[0]].push_back(e[1]);
        }
        dfs(1);
        build(1, 1, n);
        vector<int> res;
        for (auto &op: operations) {
            int t = op[0];
            if (t == 1) {
                update(1, L[op[1]], L[op[1]], op[2]);
            } else if (t == 2) {
                update(1, L[op[1]], R[op[1]], op[2]);
            } else {
                res.push_back(query(1, L[op[1]], R[op[1]]));
            }
        }
        return res;
    }

private:
    int tot;
    unordered_map<int, vector<int>> g;

    void dfs(int u) {
        tot++;
        L[u] = tot;
        for (int child: g[u]) {
            dfs(child);
        }
        R[u] = tot;
    }
};