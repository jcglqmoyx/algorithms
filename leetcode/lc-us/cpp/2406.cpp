#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>> &intervals) {
        const int INF = 1e9;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        multiset<int> S;
        S.insert(-INF), S.insert(INF);
        for (auto &v: intervals) {
            int x = v[0], y = v[1];
            auto it = S.lower_bound(x);
            it--;
            if (*it != -INF) {
                S.erase(it);
            }
            S.insert(y);
        }
        return (int) S.size() - 2;
    }
};