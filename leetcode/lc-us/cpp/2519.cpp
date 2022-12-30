#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> tr1, tr2;

    int low_bit(int x) {
        return x & -x;
    }

    void update(vector<int> &tr, int x, int dt) {
        while (x <= n) {
            tr[x] += dt;
            x += low_bit(x);
        }
    }

    int query(vector<int> &tr, int x) {
        int res = 0;
        while (x) {
            res += tr[x];
            x -= low_bit(x);
        }
        return res;
    }

public:
    int kBigIndices(vector<int> &nums, int k) {
        n = (int) nums.size();
        tr1.resize(n + 1), tr2.resize(n + 1);
        for (int x: nums) update(tr2, x, 1);
        int res = 0;
        for (int x: nums) {
            update(tr2, x, -1);
            if (query(tr1, x - 1) >= k && query(tr2, x - 1) >= k) {
                res++;
            }
            update(tr1, x, 1);
        }
        return res;
    }
};