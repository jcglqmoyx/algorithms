#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int INF = 1e8;
    int n;
    vector<int> f;

    void dfs(vector<int> &days, vector<int> &costs, int u, int cost) {
        if (cost >= f[u]) return;
        f[u] = min(f[u], cost);
        if (u == n) return;
        int l = u, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (days[mid] - days[u] + 1 <= 30) l = mid + 1;
            else r = mid;
        }
        dfs(days, costs, l, cost + costs[2]);

        l = u, r = n;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (days[mid] - days[u] + 1 <= 7) l = mid + 1;
            else r = mid;
        }
        dfs(days, costs, l, cost + costs[1]);

        dfs(days, costs, u + 1, cost + costs[0]);
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        n = (int) days.size();
        f.resize(n + 1, INF);
        dfs(days, costs, 0, 0);
        return f[n];
    }
};