#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = (int) scores.size();
        vector<int> t(n);
        for (int i = 0; i < n; i++) t[i] = i;
        sort(t.begin(), t.end(), [&](int a, int b) {
            if (ages[a] != ages[b]) return ages[a] < ages[b];
            return scores[a] < scores[b];
        });
        for (int i = 0; i < n; i++) t[i] = scores[t[i]];
        vector<int> f(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            f[i] = t[i];
            for (int j = 0; j < i; j++) {
                if (t[j] <= t[i]) {
                    f[i] = max(f[i], f[j] + t[i]);
                }
            }
            res = max(res, f[i]);
        }
        return res;
    }
};