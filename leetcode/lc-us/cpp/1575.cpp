#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int f[105][205];

class Solution {
    vector<pair<int, int>> v;

    int dp(vector<int> &locations, int pos, int dest, int rest) {
        if (f[pos][rest] != -1) return f[pos][rest];
        f[pos][rest] = 0;
        for (int i = 0; i < locations.size(); i++) {
            if (i == pos) continue;
            int d = abs(locations[i] - locations[pos]);
            if (d > rest) continue;
            f[pos][rest] = (f[pos][rest] + dp(locations, i, dest, rest - d)) % MOD;
        }
        if (pos == dest) f[pos][rest] = (f[pos][rest] + 1) % MOD;
        return f[pos][rest];
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
        int n = (int) locations.size();
        v.reserve(n);
        for (int i = 0; i < n; i++) {
            v.emplace_back(locations[i], i);
        }
        sort(v.begin(), v.end());

        memset(f, -1, sizeof(f));
        return dp(locations, start, finish, fuel);
    }
};