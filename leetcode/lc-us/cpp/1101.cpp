#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int earliestAcq(vector<vector<int>> &logs, int n) {
        f.resize(n, 0);
        rank.resize(n, 1);
        count = n;
        for (int i = 0; i < n; i++) f[i] = i;
        sort(logs.begin(), logs.end());
        for (auto &log: logs) {
            connect(log[1], log[2]);
            if (count == 1) return log[0];
        }
        return -1;
    }

private:
    vector<int> f;
    vector<int> rank;
    int count;

    int find(int x) {
        return f[x] == x ? x : find(f[x]);
    }

    void connect(int x, int y) {
        int fx = find(x);
        int fy = find(y);
        if (fx == fy) return;
        if (fx < fy) swap(fx, fy);
        f[fy] = f[fx];
        rank[fx]++;
        count--;
    }
};