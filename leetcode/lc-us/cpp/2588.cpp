#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long beautifulSubarrays(vector<int> &nums) {
        long long res = 0;
        int st = 0;
        unordered_map<int, int> S;
        S[0] = 1;
        for (int x: nums) {
            int mask = 0;
            for (int i = 0; i < 21; i++) {
                st ^= 1 << i & x;
                mask |= 1 << i & st;
            }
            res += S[mask];
            S[mask]++;
        }
        return res;
    }
};