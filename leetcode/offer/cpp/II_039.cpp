#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0, n = (int) heights.size();
        vector<int> l(n), r(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) l[i] = -1;
            else l[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) r[i] = n;
            else r[i] = stk.top();
            stk.push(i);
        }
        for (int i = 0; i < n; i++) res = max(res, heights[i] * (r[i] - l[i] - 1));
        return res;
    }
};