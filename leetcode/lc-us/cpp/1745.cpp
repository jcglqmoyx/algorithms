#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    const int P = 131;

    vector<ULL> p;

    ULL get(vector<ULL> &h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

public:
    bool checkPartitioning(string s) {
        int n = (int) s.size();

        string t = string(s.rbegin(), s.rend());

        vector<ULL> h1(n + 1), h2(n + 1);
        p.resize(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h1[i] = h1[i - 1] * P + s[i - 1];
            h2[i] = h2[i - 1] * P + t[i - 1];
        }

        for (int i = 2; i <= n - 1; i++) {
            for (int j = i; j <= n - 1; j++) {
                if (get(h1, i, j) == get(h2, n + 1 - j, n + 1 - i)
                    && get(h1, 1, i - 1) == get(h2, n - i + 2, n)
                    && get(h1, j + 1, n) == get(h2, 1, n - j)) {
                    return true;
                }
            }
        }
        return false;
    }
};