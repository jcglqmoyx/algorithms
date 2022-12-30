#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaximumNumber(vector<vector<int>> &moles) {
        vector<vector<int>> A;
        bool flag = false;
        for (auto &mole: moles) {
            if (mole[0] == 0) {
                if (mole[1] == 1 && mole[2] == 1) flag = true;
            } else {
                A.push_back(mole);
            }
        }
        A.push_back(vector<int>{0, 1, 1});

        int n = (int) A.size();
        sort(A.begin(), A.end());
        vector<int> f(n), g(n);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            f[i] = -1e8;
            for (int j = i - 1; j >= 0; j--) {
                int t = A[i][0] - A[j][0], d = abs(A[i][1] - A[j][1]) + abs(A[i][2] - A[j][2]);
                if (t > 4) {
                    f[i] = max(f[i], g[j] + 1);
                    break;
                } else if (d <= t) f[i] = max(f[i], f[j] + 1);
            }
            ans = max(ans, f[i]);
            g[i] = max(g[i - 1], f[i]);
        }
        return ans + (flag ? 1 : 0);
    }
};