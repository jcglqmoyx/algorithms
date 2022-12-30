#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> stk;
        for (int x: asteroids) {
            stk.push(x);
            while (stk.size() >= 2) {
                int m = stk.top();
                stk.pop();
                int n = stk.top();
                stk.pop();
                if (n > 0 && m < 0) {
                    if (n == -m) continue;
                    else if (n < -m) stk.push(m);
                    else if (n > -m) stk.push(n);
                } else {
                    stk.push(n);
                    stk.push(m);
                    break;
                }
            }
        }
        vector<int> res;
        while (!stk.empty()) {
            int t = stk.top();
            stk.pop();
            res.push_back(t);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};