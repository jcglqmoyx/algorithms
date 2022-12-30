#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1ll << 60;

struct Mono {
    map<ll, ll> mp;

    void init(ll x = -INF, ll y = 0) {
        mp.clear();
        mp[x] = y;
    }

    ll query(ll x) {
        auto cur = mp.upper_bound(x);
        cur--;
        return cur->second;
    }

    void insert(ll x, ll y) {
        if (query(x) >= y) return;
        for (auto cur = mp.lower_bound(x), pre = cur;
             cur != mp.end() && cur->second <= y; cur++, mp.erase(pre), pre = cur);
        mp[x] = y;
    }
} P, Q;

class Solution {
public:
    int processTasks(vector<vector<int>> &tasks) {
        sort(tasks.begin(), tasks.end());
        P.init();
        Q.init(-INF, -INF);
        for (auto &t: tasks) {
            ll x_p = t[0], x_q = t[1] + 1;
            ll y_p = max(P.query(x_p), x_p + Q.query(-x_p)), y_q = y_p + t[2];
            P.insert(x_q, y_q);
            Q.insert(-x_q, y_q - x_q);
        }
        return (int) P.query(INF);
    }
};