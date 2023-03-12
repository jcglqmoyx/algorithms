#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinimumTime(vector<vector<int>> &tasks) {
        bool st[2001]{};
        sort(tasks.begin(), tasks.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        int res = 0;
        for (auto &t: tasks) {
            int s = t[0], e = t[1], d = t[2];
            for (int i = s; i <= e; i++) {
                if (st[i]) d--;
            }
            for (int i = e; d > 0; i--) {
                if (!st[i]) st[i] = true, d--, res++;
            }
        }
        return res;
    }
};