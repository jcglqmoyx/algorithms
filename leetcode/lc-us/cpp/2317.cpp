#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumXOR(vector<int> &nums) {
        int f[32] = {};
        for (int x: nums) {
            for (int i = 0; x && i < 32; i++) {
                if (x >> i & 1) {
                    f[i]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if (f[i]) {
                res += 1 << i;
            }
        }
        return res;
    }
};