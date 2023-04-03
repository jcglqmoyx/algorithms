#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        bool st[100010]{};
        for (int x: banned) st[x] = true;

        vector<set<int>> s(2);
        for (int i = 0; i < n; i++) {
            if (!st[i]) s[i & 1].insert(i);
        }

        vector<int> res(n, -1);
        res[p] = 0;
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            for (auto iter = q.size(); iter; iter--) {
                int t = q.front();
                q.pop();
                s[t & 1].erase(t);
                int l = t - k + 1, r = t + k - 1;
                if (t < k - 1) l = k - 1 - t;
                if (t + k > n) r = n * 2 - k - t - 1;

                auto &set = s[(t + k) & 1 ^ 1];
                auto it = set.lower_bound(l);

                while (it != set.end() && *it <= r) {
                    res[*it] = res[t] + 1;
                    q.push(*it);
                    it = set.erase(it);
                }
            }
        }
        return res;
    }
};