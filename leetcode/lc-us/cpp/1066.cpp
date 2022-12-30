#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int assignBikes(vector<vector<int>> &workers, vector<vector<int>> &bikes) {
        memset(st, false, sizeof st);
        n = (int) workers.size(), m = (int) bikes.size();
        dfs(workers, bikes, 0, 0);
        return res;
    }

private:
    int n{}, m{};
    int res = 1e9;
    bool st[10]{};

    static int get(vector<int> &worker, vector<int> &bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }

    void dfs(vector<vector<int>> &workers, vector<vector<int>> &bikes, int u, int dist) {
        if (dist >= res) return;
        if (u == n) {
            res = min(res, dist);
            return;
        }
        for (int i = 0; i < m; i++) {
            if (!st[i]) {
                st[i] = true;
                dfs(workers, bikes, u + 1, dist + get(workers[u], bikes[i]));
                st[i] = false;
            }
        }
    }
};