/*
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        int n = (int) s.size();
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = min(i, f[i - 1] + 1);
            for (auto &t: dictionary) {
                if (t.size() <= i && s.substr(i - t.size(), t.size()) == t) f[i] = min(f[i], f[i - t.size()]);
            }
        }
        return f[n];
    }
};
 */

#include <bits/stdc++.h>

using namespace std;

using ULL = unsigned long long;

const int N = 55, P = 131;

int n;
ULL p[N], h[N];

void init(string &s) {
    n = (int) s.size();
    p[0] = 1, h[0] = 0;
    for (int i = 1; i <= n; i++) p[i] = p[i - 1] * P;
    for (int i = 1; i <= n; i++) h[i] = h[i - 1] * P + s[i - 1];
}

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        n = (int) s.size();
        init(s);
        int f[n + 1];
        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = min(i, f[i - 1] + 1);
            for (auto &t: dictionary) {
                int m = (int) t.size();
                if (m > i) continue;
                ULL ht = 0;
                for (char c: t) ht = ht * P + c;
                if (get(i - m + 1, i) == ht) f[i] = min(f[i], f[i - m]);
            }
        }
        return f[n];
    }
};