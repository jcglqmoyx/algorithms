#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    LL gcd(LL x, LL y) {
        return x % y ? gcd(y, x % y) : y;
    }

    vector<LL> add(vector<LL> a, vector<LL> b) {
        LL x = a[0] * b[1] + b[0] * a[1], y = a[1] * b[1];
        if (!y) return a;
        LL greatest_common_ancestor = gcd(x, y);
        return {x / greatest_common_ancestor, y / greatest_common_ancestor};
    }

    vector<LL> get(string &s) {
        LL a = 0, b = 1;
        int u = 0;
        while (u < s.size() && s[u] != '.') {
            a = a * 10 + s[u] - '0';
            u++;
        }
        int p1 = u;
        vector<LL> res = {a, b};
        a = 0, b = 1;
        u++;
        while (u < s.size() && s[u] != '(') {
            a = a * 10 + s[u] - '0';
            b = b * 10;
            u++;
        }

        u++;
        int p2 = u;

        res = add(res, {a, b});
        a = 0, b = 0;
        while (u < s.size() && s[u] != ')') {
            a = a * 10 + s[u] - '0';
            b = b * 10 + 9;
            u++;
        }

        res = add(res, {a, b * (LL) pow(10, p2 - p1 - 2)});
        return res;
    }

public:
    bool isRationalEqual(string s, string t) {
        return get(s) == get(t);
    }
};