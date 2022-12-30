#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<string> &matrix) {
        if (matrix.empty()) return 0;
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> h(n + 1, vector<int>(m));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i - 1][j] == '1') {
                    h[i][j] = 1 + h[i - 1][j];
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            stack<int> stk;
            vector<int> l(m), r(m);
            for (int j = 0; j < m; j++) {
                while (!stk.empty() && h[i][stk.top()] >= h[i][j]) stk.pop();
                if (stk.empty()) l[j] = -1;
                else l[j] = stk.top();
                stk.push(j);
            }
            while (!stk.empty()) stk.pop();
            for (int j = m - 1; j >= 0; j--) {
                while (!stk.empty() && h[i][stk.top()] >= h[i][j]) stk.pop();
                if (stk.empty()) r[j] = m;
                else r[j] = stk.top();
                stk.push(j);
            }
            for (int j = 0; j < m; j++) {
                res = max(res, h[i][j] * (r[j] - l[j] - 1));
            }
        }
        return res;
    }
};