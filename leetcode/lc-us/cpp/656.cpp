#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> cheapestJump(vector<int> &coins, int maxJump) {
        vector<int> res;
        int n = (int) coins.size(), INF = 1e8;
        if (coins[n - 1] == -1) return res;
        vector<int> f(n, INF);
        f[n - 1] = coins[n - 1];
        deque<int> q;
        q.push_back(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            if (coins[i] == -1) {
                continue;
            }
            while (!q.empty() && q.front() - i > maxJump) q.pop_front();
            if (!q.empty()) {
                f[i] = f[q.front()] + coins[i];
                while (!q.empty() && f[q.back()] > f[i]) {
                    q.pop_back();
                }
            }
            q.push_back(i);
        }

        if (f[0] >= INF) return res;
        res.push_back(1);
        int i = 0, v = f[0];
        while (i != n - 1) {
            for (int j = i + 1; j <= max(n - 1, i + maxJump); j++) {
                if (f[j] + coins[i] == v) {
                    i = j, v = f[j];
                    res.push_back(j + 1);
                    break;
                }
            }
        }
        return res;
    }
};