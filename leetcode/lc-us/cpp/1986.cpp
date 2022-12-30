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