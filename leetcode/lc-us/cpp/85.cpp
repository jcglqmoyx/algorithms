#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int res = 0;
        if (matrix.empty() || matrix[0].empty()) return res;
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        vector<vector<int>> h(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    if (!i) h[i][j] = 1;
                    else h[i][j] = h[i - 1][j] + 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            stack<int> stk;
            vector<int> left(m), right(m);
            for (int j = 0; j < m; j++) {
                while (!stk.empty() && h[i][stk.top()] >= h[i][j]) stk.pop();
                if (stk.empty()) left[j] = -1;
                else left[j] = stk.top();
                stk.push(j);
            }
            stk = stack<int>();
            for (int j = m - 1; j >= 0; j--) {
                while (!stk.empty() && h[i][stk.top()] >= h[i][j]) stk.pop();
                if (stk.empty()) right[j] = m;
                else right[j] = stk.top();
                stk.push(j);
            }
            for (int j = 0; j < m; j++) {
                res = max(res, h[i][j] * (right[j] - left[j] - 1));
            }
        }
        return res;
    }
};