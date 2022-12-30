#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = (int) questions.size();
        vector<long long> f(n);
        for (int i = n - 1; i >= 0; i--) {
            int p = questions[i][0], b = questions[i][1];
            f[i] = p;
            if (i + b + 1 < n) f[i] += f[i + b + 1];
            if (i < n - 1) f[i] = max(f[i], f[i + 1]);
        }
        return f[0];
    }
};