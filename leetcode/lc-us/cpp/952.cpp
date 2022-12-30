#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n, res;
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void connect(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
        res = max(res, rk[py]);
    }

public:
    int largestComponentSize(vector<int> &nums) {
        n = *max_element(nums.begin(), nums.end()) + 1, res = 1;
        p.resize(n), rk.resize(n, 1);
        for (int i = 1; i < n; i++) p[i] = i;

        vector<bool> exits(n);
        for (int x: nums) exits[x] = true;
        for (int i = 2; i <= max(2, (n - 1) / 2); i++) {
            int prev = 0;
            for (int j = i; j < n; j += i) {
                if (exits[j]) {
                    if (prev) {
                        connect(prev, j);
                    }
                    prev = j;
                }
            }
        }
        return res;
    }
};