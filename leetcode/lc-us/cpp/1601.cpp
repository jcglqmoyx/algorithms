#include <bits/stdc++.h>

using namespace std;

class Solution {
    int res, m;
    vector<int> cnt;
    vector<vector<int>> _requests;

    void dfs(int u, int count_request, int invalid) {
        if (u == m) {
            if (invalid == 0) res = max(res, count_request);
            return;
        }
        dfs(u + 1, count_request, invalid);
        int from = _requests[u][0], to = _requests[u][1];
        cnt[from]--, cnt[to]++;
        int dt = 0;
        if (from != to) {
            if (cnt[from] == -1) dt++;
            else if (cnt[from] == 0) dt--;
            if (cnt[to] == 1) dt++;
            else if (cnt[to] == 0) dt--;
        }
        dfs(u + 1, count_request + 1, invalid + dt);
        cnt[from]++, cnt[to]--;
    }

public:
    int maximumRequests(int n, vector<vector<int>> &requests) {
        res = 0, m = (int) requests.size(), _requests = requests, cnt.resize(n);
        dfs(0, 0, 0);
        return res;
    }
};