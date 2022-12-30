#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> seePeople(vector<vector<int>> &heights) {
        int n = (int) heights.size(), m = (int) heights[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty()) stk.pop();
            for (int j = m - 1; ~j; j--) {
                bool flag = false;
                while (!stk.empty() && heights[i][stk.top()] <= heights[i][j]) {
                    res[i][j]++;
                    if (heights[i][stk.top()] == heights[i][j]) flag = true;
                    stk.pop();
                }
                if (!stk.empty() && !flag) {
                    res[i][j]++;
                }
                stk.push(j);
            }
        }

        for (int j = 0; j < m; j++) {
            while (!stk.empty()) stk.pop();
            for (int i = n - 1; ~i; i--) {
                bool flag = false;
                while (!stk.empty() && heights[stk.top()][j] <= heights[i][j]) {
                    res[i][j]++;
                    if (heights[stk.top()][j] == heights[i][j]) flag = true;
                    stk.pop();
                }
                if (!stk.empty() && !flag) {
                    res[i][j]++;
                }
                stk.push(i);
            }
        }
        return res;
    }
};