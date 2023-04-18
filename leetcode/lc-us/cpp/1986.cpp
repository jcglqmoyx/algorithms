/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        idx = 0, n = (int) tasks.size(), res = n, t = tasks, session.resize(n), session_time = sessionTime;
        dfs(0);
        return res;
    }

private:
    int n, res;
    int idx;
    int session_time;
    vector<int> t;
    vector<int> session;

    void dfs(int u) {
        if (idx >= res) return;
        if (u == n) {
            res = idx;
            return;
        }
        for (int i = 0; i < idx; i++) {
            if (session[i] + t[u] <= session_time) {
                session[i] += t[u];
                dfs(u + 1);
                session[i] -= t[u];
            }
        }
        session[idx] += t[u];
        idx++;
        dfs(u + 1);
        session[--idx] -= t[u];
    }
};
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSessions(vector<int> &tasks, int sessionTime) {
        int n = (int) tasks.size();
        vector<pair<int, int>> f(1 << n, {INT_MAX, INT_MAX});
        f[0] = {1, 0};

        auto add = [&](const pair<int, int> &o, int x) -> pair<int, int> {
            if (o.second + x <= sessionTime) {
                return {o.first, o.second + x};
            }
            return {o.first + 1, x};
        };

        for (int mask = 1; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    f[mask] = min(f[mask], add(f[mask ^ (1 << i)], tasks[i]));
                }
            }
        }
        return f[(1 << n) - 1].first;
    }
};