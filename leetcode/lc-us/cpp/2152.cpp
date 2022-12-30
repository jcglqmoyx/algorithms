#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool on_same_line(vector<int> &a, vector<int> &b, vector<int> &c) {
        return (a[1] - b[1]) * (a[0] - c[0]) == (a[1] - c[1]) * (a[0] - b[0]);
    }

    inline bool in(int x, int y) {
        while (y) {
            int k = y & -y;
            if (!(x & k)) {
                return false;
            }
            y -= k;
        }
        return true;
    }

public:
    int minimumLines(vector<vector<int>> &points) {
        int n = (int) points.size(), m = 1 << n;
        vector<int> f(m);
        for (int i = 1; i < m; i++) {
            if (__builtin_popcount(i) <= 2) {
                f[i] = 1;
            } else {
                bool flag = true;
                int a = -1, b = -1;
                for (int j = 0; j < n; j++) {
                    if (i >> j & 1) {
                        if (a == -1) {
                            a = j;
                        } else if (b == -1) {
                            b = j;
                        } else {
                            if (!on_same_line(points[a], points[b], points[j])) {
                                flag = false;
                                break;
                            }
                        }
                    }
                }
                if (flag) f[i] = 1;
                else {
                    f[i] = n;
                    for (int j = 1; j < i; j++) {
                        if (in(i, j)) {
                            int k = i - j;
                            f[i] = min(f[i], f[j] + f[k]);
                        }
                    }
                }
            }
        }
        return f[(1 << n) - 1];
    }
};