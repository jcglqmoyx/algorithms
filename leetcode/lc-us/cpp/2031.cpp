#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> tr;

    int lb(int x) {
        return x & -x;
    }

    int query(int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= lb(x);
        }
        return res;
    }

    void update(int x, int dt) {
        while (x <= n) {
            tr[x] += dt;
            x += lb(x);
        }
    }

public:
    int subarraysWithMoreZerosThanOnes(vector<int> &nums) {
        int MOD = 1e9 + 7, offset = 1e5 + 1;
        n = 2e5 + 5;
        tr.resize(n + 1);
        int res = 0, sum = 0;
        update(0 + offset, 1);
        for (int x: nums) {
            if (x) sum++;
            else sum--;
            res += query(sum - 1 + offset);
            res %= MOD;
            update(sum + offset, 1);
        }
        return res;
    }
};