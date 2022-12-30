#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int> &nums) {
        vector<int> res;
        int cnt[1000005] = {};
        for (int x: nums) cnt[x]++;
        for (int x: nums) {
            if (x == 0) {
                if (cnt[x] == 1 && !cnt[x + 1]) {
                    res.push_back(x);
                }
            } else {
                if (cnt[x] == 1 && !cnt[x + 1] && !cnt[x - 1]) {
                    res.push_back(x);
                }
            }
        }
        return res;
    }
};