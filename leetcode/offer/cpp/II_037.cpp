#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        stack<int> s;
        for (int x: asteroids) {
            s.push(x);
            while (s.size() >= 2) {
                int m = s.top();
                s.pop();
                int n = s.top();
                s.pop();
                if (n > 0 && m < 0) {
                    if (n == -m) continue;
                    else if (n < -m) s.push(m);
                    else if (n > -m) s.push(n);
                } else {
                    s.push(n);
                    s.push(m);
                    break;
                }
            }
        }
        vector<int> res;
        while (!s.empty()) {
            int t = s.top();
            s.pop();
            res.push_back(t);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};