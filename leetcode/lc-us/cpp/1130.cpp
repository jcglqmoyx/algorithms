#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        vector<int> stk;
        int res = 0;
        for (int x: arr) {
            if (stk.empty() || x < stk.back()) stk.push_back(x);
            else {
                while (!stk.empty() && x >= stk.back()) {
                    int t = stk.back();
                    stk.pop_back();
                    if (!stk.empty()) res += t * min(stk.back(), x);
                    else res += t * x;
                }
                stk.push_back(x);
            }
        }
        while (stk.size() >= 2) {
            res += stk[stk.size() - 1] * stk[stk.size() - 2];
            stk.pop_back();
        }
        return res;
    }
};