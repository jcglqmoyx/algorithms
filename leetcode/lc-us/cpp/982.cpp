#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &nums) {
        static constexpr int N = 16;
        int cnt[1 << N] = {};
        for (int x: nums) {
            for (int y: nums) {
                cnt[x & y]++;
            }
        }
        int res = 0;
        for (auto x: nums) {
            int s = x ^ ((1 << N) - 1);
            for (int y = s; y; y = (y - 1) & s) {
                res += cnt[y];
            }
            res += cnt[0];
        }
        return res;
    }
};