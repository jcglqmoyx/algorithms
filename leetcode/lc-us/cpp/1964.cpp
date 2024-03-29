#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        int n = (int) obstacles.size();
        vector<int> res(n);
        vector<int> seq;
        for (int i = 0; i < n; i++) {
            int x = obstacles[i];
            if (seq.empty() || seq.back() <= x) seq.push_back(x), res[i] = (int) seq.size();
            else {
                auto p = upper_bound(seq.begin(), seq.end(), x);
                res[i] = (int) (p - seq.begin()) + 1;
                *p = x;
            }
        }
        return res;
    }
};