#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = (int) isConnected.size();
        cnt = n;
        p.resize(n), rk.resize(n);
        for (int i = 0; i < n; i++) p[i] = i, rk[i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j]) {
                    add(i, j);
                }
            }
        }
        return cnt;
    }

private:
    int cnt;
    vector<int> p, rk;

    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;
        if (rk[px] < rk[py]) swap(px, py);
        p[py] = px;
        rk[px] += rk[py];
        cnt--;
    }
};