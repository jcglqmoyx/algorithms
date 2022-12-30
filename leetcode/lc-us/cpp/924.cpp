#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> p, cnt, size;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial) {
        int n = (int) graph.size();
        p.resize(n), cnt.resize(n), size.resize(n, 1);
        for (int i = 0; i < n; i++) p[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (graph[i][j]) {
                    int pi = find(i), pj = find(j);
                    if (pi == pj) continue;
                    p[pj] = pi;
                    size[pi] += size[pj];
                }
            }
        }
        for (int x: initial) cnt[find(x)]++;
        int mx = 0, res = INT32_MAX;
        for (int x: initial) {
            int root = find(x);
            if (cnt[root] == 1) {
                if (size[root] > mx) {
                    mx = size[root];
                    res = x;
                } else if (size[root] == mx) {
                    res = min(res, x);
                }
            } else {
                res = min(res, x);
            }
        }
        return res;
    }
};