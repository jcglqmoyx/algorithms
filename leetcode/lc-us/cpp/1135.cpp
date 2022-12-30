#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>> &connections) {
        p.resize(n + 1), rk.resize(n + 1, 1);
        for (int i = 0; i < n + 1; i++) p[i] = i;
        sort(connections.begin(), connections.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        int res = 0;
        for (auto &c: connections) {
            int px = find(c[0]), py = find(c[1]);
            if (px == py) continue;
            if (px > py) swap(px, py);
            p[px] = py, rk[py] += rk[px];
            res += c[2];
            n--;
        }
        if (n == 1) return res;
        return -1;
    }

private:
    vector<int> p, rk;

    int find(int x) {
        if (x != p[x]) p[x] = find(p[x]);
        return p[x];
    }
};