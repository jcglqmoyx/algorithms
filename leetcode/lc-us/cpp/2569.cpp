#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 100010;

struct Node {
    int l, r, cnt;
    bool flip;
} tr[N << 2];

void push_down(int u) {
    tr[u].cnt = tr[u].r - tr[u].l + 1 - tr[u].cnt;
    tr[u].flip ^= true;
}

void push_up(int u) {
    tr[u].cnt = tr[u << 1].cnt + tr[u << 1 | 1].cnt;
}

void build(vector<int> &nums, int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) tr[u].cnt = nums[l];
    else {
        int mid = (l + r) >> 1;
        build(nums, u << 1, l, mid), build(nums, u << 1 | 1, mid + 1, r);
        push_up(u);
    }
}

void update(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        push_down(u);
    } else {
        if (tr[u].flip) {
            push_down(u << 1), push_down(u << 1 | 1);
            tr[u].flip = false;
        }
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (l <= mid) update(u << 1, l, r);
        if (r > mid) update(u << 1 | 1, l, r);
        push_up(u);
    }
}

class Solution {
public:
    vector<long long> handleQuery(vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &queries) {
        int n = (int) nums1.size();
        build(nums1, 1, 0, n - 1);
        LL s = accumulate(nums2.begin(), nums2.end(), 0LL);
        vector<LL> res;
        for (auto &q: queries) {
            int type = q[0];
            if (type == 1) update(1, q[1], q[2]);
            else if (type == 2) s += tr[1].cnt * (LL) q[1];
            else res.push_back(s);
        }
        return res;
    }
};