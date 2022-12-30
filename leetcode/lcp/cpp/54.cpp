#include <bits/stdc++.h>

using namespace std;

class Solution {
    const int S = 0;
    int n;

    vector<vector<int>> e;
    vector<bool> isCut;
    vector<int> dfn, low;
    int clk = 0;
    stack<int> stk;
    vector<vector<int>> dcc;

    void tarjan(int sn) {
        dfn[sn] = low[sn] = ++clk;
        stk.push(sn);
        int flag = 0;
        for (int fn: e[sn]) {
            if (!dfn[fn]) {
                tarjan(fn);
                low[sn] = min(low[sn], low[fn]);
                if (low[fn] >= dfn[sn]) {
                    flag++;
                    if (sn != S || flag > 1) isCut[sn] = true;
                    int t;
                    dcc.emplace_back();
                    do {
                        t = stk.top();
                        stk.pop();
                        dcc.back().push_back(t);
                    } while (t != fn);
                    dcc.back().push_back(sn);
                }
            } else low[sn] = min(low[sn], dfn[fn]);
        }
    }

public:
    long long minimumCost(vector<int> &cost, vector<vector<int>> &roads) {
        n = (int) cost.size();
        if (n == 1) return cost[0];

        e = vector<vector<int>>(n);
        for (auto &r: roads) e[r[0]].push_back(r[1]), e[r[1]].push_back(r[0]);
        isCut = vector<bool>(n);
        dfn = low = vector<int>(n);
        tarjan(S);

        if (dcc.size() == 1) {
            int ans = 2e9;
            for (int x: cost) ans = min(ans, x);
            return ans;
        }

        vector<int> vec;
        for (auto &c: dcc) {
            int cnt = 0, mn = 2e9;
            for (int x: c) {
                if (isCut[x]) cnt++;
                else mn = min(mn, cost[x]);
            }
            if (cnt == 1) vec.push_back(mn);
        }
        sort(vec.begin(), vec.end());
        long long ans = 0;
        for (int i = 0; i + 1 < vec.size(); i++) ans += vec[i];
        return ans;
    }
};