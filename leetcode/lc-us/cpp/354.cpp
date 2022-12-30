#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = (int) envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &e1, vector<int> &e2) {
            return e1[0] < e2[0] || e1[0] == e2[0] && e1[1] > e2[1];
        });
        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; i++) {
            int num = envelopes[i][1];
            if (num > f.back()) {
                f.push_back(num);
            } else {
                auto position = lower_bound(f.begin(), f.end(), num);
                *position = num;
            }
        }
        return (int) f.size();
    }
};