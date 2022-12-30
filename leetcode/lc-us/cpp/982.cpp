#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int> &nums) {
        static constexpr int N = 16;
        int cnt[1 << N] = {};
        int n = (int) nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cnt[nums[i] & nums[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 1 << N; i++) {
            for (auto x: nums) {
                if (!(x & i)) {
                    res += cnt[i];
                }
            }
        }
        return res;
    }
};