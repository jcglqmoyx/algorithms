#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p, sz;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

public:
    int minSwapsCouples(vector<int> &row) {
        int n = (int) row.size() / 2, cnt = n;
        p.resize(n), sz.resize(n);
        for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
        for (int i = 0; i < n << 1; i += 2) {
            int a = row[i] / 2, b = row[i + 1] / 2;
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                if (sz[pa] < sz[pb]) swap(pa, pb);
                p[pb] = pa;
                sz[pa] += sz[pb];
                cnt--;
            }
        }
        return n - cnt;
    }
};