#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        int res = 0;
        unordered_set<int> exists;
        sort(nums.begin(), nums.end());
        int last = 0;
        for (int x: nums) {
            if (exists.count(x)) {
                for (int y = max(last, x);; y++) {
                    if (!exists.count(y)) {
                        last = y;
                        res += y - x;
                        exists.insert(y);
                        break;
                    }
                }
            } else {
                exists.insert(x);
            }
        }
        return res;
    }
};