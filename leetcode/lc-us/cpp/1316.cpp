#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ULL = unsigned long long;
    const int P = 131;

    static ULL get(vector<ULL> &p, vector<ULL> &h, int low, int high) {
        return h[high] - h[low - 1] * p[high - low + 1];
    }

public:
    int distinctEchoSubstrings(string text) {
        int n = (int) text.size();
        vector<ULL> h(n + 1), p(n + 1);
        p[0] = 1;
        for (int i = 1; i <= n; i++) {
            p[i] = p[i - 1] * P;
            h[i] = h[i - 1] * P + text[i - 1];
        }
        unordered_set<ULL> S;
        for (int len = 2; len <= n; len += 2) {
            for (int i = 1; i + len - 1 <= n; i++) {
                ULL h1 = get(p, h, i, i + len / 2 - 1), h2 = get(p, h, i + len / 2, i + len - 1);
                if (h1 == h2) S.insert(h1);
            }
        }
        return (int) S.size();
    }
};