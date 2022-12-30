#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSimilarGroups(vector<string> &strs) {
        int n = (int) strs.size();
        p.resize(n), rk.resize(n);
        for (int i = 0; i < n; i++) p[i] = i, rk[i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (similar(strs[i], strs[j])) {
                        add(i, j);
                    }
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) if (p[i] == i) cnt++;
        return cnt;
    }

private:
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] > rk[py]) swap(px, py);
        p[px] = py;
        rk[py] += rk[px];
    }

    bool similar(string a, string &b) {
        int diff = 0;
        for (int idx = 0; idx < a.size(); idx++) {
            if (a[idx] != b[idx]) {
                diff++;
                if (diff > 2) return false;
            }
        }
        return diff == 2 || diff == 0;
    }
};