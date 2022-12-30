#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int flipgame(vector<int> &fronts, vector<int> &backs) {
        const int INF = 1e9;
        int n = (int) fronts.size();
        unordered_set<int> set;
        for (int i = 0; i < n; i++) {
            if (fronts[i] == backs[i]) {
                set.insert(fronts[i]);
            }
        }
        int res = INF;
        for (int i = 0; i < n; i++) {
            if (set.find(fronts[i]) == set.end()) {
                res = min(res, fronts[i]);
            }
            if (set.find(backs[i]) == set.end()) {
                res = min(res, backs[i]);
            }
        }
        return res == INF ? 0 : res;
    }
};