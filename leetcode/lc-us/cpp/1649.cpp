#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> tr;

    int lowbit(int x) {
        return x & -x;
    }

    void update(int x, int dt) {
        while (x <= n) tr[x] += dt, x += lowbit(x);
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= lowbit(x);
        }
        return res;
    }

public:
    int createSortedArray(vector<int> &instructions) {
        const int MOD = 1e9 + 7;
        n = 100010;
        tr.resize(n + 1);
        int res = 0;
        for (int x: instructions) {
            int l = query(x - 1), r = query(n) - query(x);
            int score = min(l, r);
            res = (res + score) % MOD;
            update(x, 1);
        }
        return res;
    }
};