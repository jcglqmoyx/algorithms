#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get(int x) {
        int res = 0;
        for (int i = 2; i * i <= x; i++) {
            while (x % i == 0) {
                res += i;
                x /= i;
            }
        }
        if (x > 1) res += x;
        return res;
    }

public:
    int smallestValue(int n) {
        int res = n;
        unordered_set<int> S;
        S.insert(n);
        while (true) {
            int t = get(n);
            res = min(res, t);
            if (S.count(t)) break;
            S.insert(t);
            n = t;
        }
        return res;
    }
};