#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>> &cars) {
        int n = (int) cars.size();
        stack<int> stk;
        vector<double> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int t;
            while (!stk.empty()) {
                t = stk.top();
                if (cars[t][1] >= cars[i][1]) stk.pop();
                else {
                    if (res[t] == -1) break;
                    else {
                        double d = cars[t][0] - cars[i][0];
                        if (res[t] * (cars[i][1] - cars[t][1]) < d) stk.pop();
                        else break;
                    }
                }
            }
            if (stk.empty()) res[i] = -1;
            else {
                res[i] = (double) (cars[t][0] - cars[i][0]) / (cars[i][1] - cars[t][1]);
            }
            stk.push(i);
        }
        return res;
    }
};