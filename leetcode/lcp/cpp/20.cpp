#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int busRapidTransit(int target, int inc, int dec, vector<int> &jump, vector<int> &cost) {
        using ll = long long;
        using PLL = pair<ll, ll>;
        const ll M = 1e9 + 7;
        int n = (int) jump.size();

        priority_queue<PLL, vector<PLL>, greater<>> q;
        unordered_set<ll> seen;

        q.emplace(0, (ll) target);
        seen.insert(target);

        ll ans = (ll) inc * target;

        while (!q.empty()) {
            auto[time, position] = q.top();
            q.pop();

            if (time >= ans) continue;
            ans = min(ans, time + position * (ll) inc);

            for (int i = 0; i < n; i++) {
                ll feed = position % (ll) jump[i], next = position / (ll) jump[i];
                if (feed == 0) {
                    if (!seen.count(next)) {
                        q.emplace(time + (ll) cost[i], next);
                    }
                } else {
                    if (!seen.count(next)) {
                        q.emplace(time + cost[i] + (ll) feed * inc, next);
                    }
                    if (!seen.count(next + 1)) {
                        q.emplace(time + cost[i] + (ll) (jump[i] - feed) * dec, next + 1);
                    }
                }
            }
        }
        return (int) (ans % M);
    }
};