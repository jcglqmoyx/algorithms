#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int destroyTargets(vector<int> &nums, int space) {
        unordered_map<int, int> cnt;
        for (int x: nums) cnt[x % space]++;
        map<int, unordered_set<int>> M;
        for (auto[k, v]: cnt) {
            M[v].insert(k);
        }
        int res = 1e9;
        for (int x: nums) {
            if (M.rbegin()->second.count(x % space)) {
                res = min(res, x);
            }
        }
        return res;
    }
};