#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countNicePairs(vector<int> &nums) {
        unordered_map<int, int> cnt;
        for (int n: nums) {
            string s = to_string(n);
            reverse(s.begin(), s.end());
            int m = stoi(s);
            cnt[n - m]++;
        }
        long long res = 0, MOD = 1e9 + 7;
        for (auto[k, v]: cnt) {
            res = (res + (long) (v - 1) * v / 2) % MOD;
        }
        return (int) res;
    }
};