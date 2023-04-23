#include <bits/stdc++.h>

using namespace std;

const int N = 55;

struct {
    int l, r;
    int g;
} tr[N << 2];

void build(vector<int> &nums, int u, int l, int r) {
    if (l > r) return;
    tr[u] = {l, r};
    if (l == r) tr[u].g = nums[l];
    else {
        int mid = (l + r) >> 1;
        build(nums, u << 1, l, mid);
        build(nums, u << 1 | 1, mid + 1, r);
        tr[u].g = gcd(tr[u << 1].g, tr[u << 1 | 1].g);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].g;
    int mid = (tr[u].l + tr[u].r) >> 1;
    int res = 0;
    if (l <= mid) res = gcd(res, query(u << 1, l, r));
    if (r > mid) res = gcd(res, query(u << 1 | 1, l, r));
    return res;
}

class Solution {
public:
    int minOperations(vector<int> &nums) {
        int n = (int) nums.size(), cnt1 = 0, g = 0;
        for (int x: nums) {
            if (x == 1) cnt1++;
            g = gcd(g, x);
        }
        if (g != 1) return -1;
        if (cnt1) return n - cnt1;

        build(nums, 1, 0, n - 1);
        int res = n * 2;
        for (int i = 0, j = 0; j < n;) {
            while (j < n && query(1, i, j) != 1) j++;
            if (j < n) res = min(res, j - i + n - 1), i++;
        }
        return res;
    }
};