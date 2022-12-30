#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstDayBeenInAllRooms(vector<int> &nextVisit) {
        const int MOD = 1e9 + 7;
        int n = (int) nextVisit.size();
        long long f[n];
        memset(f, 0, sizeof f);
        f[0] = 0;
        f[1] = 2;
        for (int i = 2; i < n; i++) {
            int x = nextVisit[i - 1];
            if (x == i - 1) f[i] = f[i - 1] + 2;
            else f[i] = f[i - 1] * 2 - f[x] + 2;
            f[i] = (f[i] + MOD) % MOD;
        }
        return (int) f[n - 1];
    }
};