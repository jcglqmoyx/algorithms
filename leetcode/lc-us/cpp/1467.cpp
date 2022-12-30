#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double getProbability(vector<int> &balls) {
        int n = (int) balls.size(), tot = 0;
        for (int x: balls) tot += x;
        double fact[tot + 1];
        fact[0] = fact[1] = 1;
        for (int i = 2; i <= tot; i++) {
            fact[i] = fact[i - 1] * i;
        }

        vector<int> left, right;
        double a = 0, b = fact[tot];
        for (int x: balls) b /= fact[x];

        function<void(int)> dfs = [&](int u) {
            if (u == n) {
                if (left.size() == right.size()) {
                    int sl = 0, sr = 0;
                    for (int x: left) sl += x;
                    for (int x: right) sr += x;
                    if (sl == sr) {
                        double l = fact[sl], r = fact[sr];
                        for (int x: left) l /= fact[x];
                        for (int x: right) r /= fact[x];
                        a += l * r;
                    }
                }
                return;
            }
            for (int l = 0; l <= balls[u]; l++) {
                int r = balls[u] - l;
                if (l) left.push_back(l);
                if (r) right.push_back(r);
                dfs(u + 1);
                if (l) left.pop_back();
                if (r) right.pop_back();
            }
        };
        dfs(0);
        return a / b;
    }
};