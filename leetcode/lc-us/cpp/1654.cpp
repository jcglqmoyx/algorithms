#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x) {
        using PII = pair<int, bool>;
        const int N = 6005;

        bool st[N][2];
        memset(st, false, sizeof st);

        for (int p: forbidden) {
            st[p][0] = st[p][1] = true;
        }
        st[0][0] = st[0][1] = true;
        queue<PII> q;
        q.push({0, 0});
        int step = 0;
        while (!q.empty()) {
            for (size_t i = q.size(); i; i--) {
                auto t = q.front();
                q.pop();
                if (t.first == x) return step;
                if (t.first + a < N && !st[t.first + a][0]) {
                    q.push({t.first + a, false});
                    st[t.first + a][0] = true;
                }
                if (!t.second && t.first - b >= 0 && !st[t.first - b][1]) {
                    q.push({t.first - b, true});
                    st[t.first - b][1] = true;
                }
            }
            step++;
        }
        return -1;
    }
};