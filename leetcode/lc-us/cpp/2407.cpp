#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int f[N];

struct Node {
    int l, r;
    int max_val;
} tr[N << 2];

void build(int u, int l, int r) {
    tr[u] = {l, r};
    int mid = (l + r) >> 1;
    if (l == r) return;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    int mid = (tr[u].l + tr[u].r) >> 1;
    auto left = Node{0, 0, 0}, right = Node{0, 0, 0};
    if (l <= mid) {
        left = query(u << 1, l, r);
    }
    if (r > mid) {
        right = query(u << 1 | 1, l, r);
    }
    return left.max_val > right.max_val ? left : right;
}

void modify(int u, int pos, int val) {
    if (tr[u].l == tr[u].r) {
        tr[u].max_val = val;
        return;
    }
    int mid = (tr[u].l + tr[u].r) >> 1;
    if (pos <= mid) modify(u << 1, pos, val);
    else modify(u << 1 | 1, pos, val);
    tr[u].max_val = max(tr[u << 1].max_val, tr[u << 1 | 1].max_val);
}

class Solution {
public:
    int lengthOfLIS(vector<int> &nums, int k) {
        memset(f, 0, sizeof f);
        build(1, 0, N - 1);
        int res = 1;
        for (int i = (int) nums.size() - 1; i >= 0; i--) {
            int x = nums[i];
            int t = query(1, x + 1, min(x + k, N - 1)).max_val;
            res = max(res, t + 1);
            modify(1, x, max(t + 1, f[x]));
            f[x] = max(f[x], t + 1);
        }
        return res;
    }
};