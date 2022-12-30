#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int> &nums) {
        unordered_set<int> S;
        int res = -1;
        for (int x: nums) {
            if (x < 0) {
                S.insert(x);
            }
        }
        for (int x: nums) {
            if (x > 0) {
                if (S.count(-x)) {
                    res = max(res, x);
                }
            }
        }
        return res;
    }
};