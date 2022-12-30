#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeTheDifference(vector<vector<int>> &mat, int target) {
        int mn = 0, mx = 0;
        for (auto &row: mat) {
            mn += *min_element(row.begin(), row.end());
            mx += *max_element(row.begin(), row.end());
        }
        if (target <= mn) return mn - target;
        else if (target >= mx) return target - mx;
        else {
            const int N = 801;
            bitset<N> f;
            f[0] = true;
            for (auto &r: mat) {
                bitset<N> g;
                for (int x: r) {
                    g |= f << x;
                }
                f = g;
            }
            int res = N;
            for (int i = 0; i < N; i++) {
                if (f[i]) {
                    res = min(res, abs(i - target));
                }
            }
            return res;
        }
    }
};