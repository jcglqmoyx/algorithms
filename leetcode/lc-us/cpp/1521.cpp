#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int> &arr, int target) {
        int res = 1e9;
        vector<int> v = {arr[0]};
        for (int x: arr) {
            res = min(res, abs(x - target));
            for (auto &e: v) {
                e &= x;
                res = min(res, abs(e - target));
            }
            v.push_back(x);
            v.erase(unique(v.begin(), v.end()), v.end());
        }
        return res;
    }
};