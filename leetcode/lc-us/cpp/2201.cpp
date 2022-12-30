#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int digArtifacts(int n, vector<vector<int>> &artifacts, vector<vector<int>> &dig) {
        int res = 0;
        unordered_set<int> S;
        for (auto &d: dig) {
            S.insert(d[0] * n + d[1]);
        }
        for (auto &a: artifacts) {
            int r1 = a[0], c1 = a[1], r2 = a[2], c2 = a[3];
            bool flag = true;
            for (int r = r1; r <= r2; r++) {
                for (int c = c1; c <= c2; c++) {
                    if (!S.count(r * n + c)) {
                        flag = false;
                        break;
                    }
                    if (!flag) break;
                }
            }
            if (flag) res++;
        }
        return res;
    }
};