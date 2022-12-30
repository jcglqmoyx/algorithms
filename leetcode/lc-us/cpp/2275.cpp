#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int cnt[32] = {};
        for (int x: candidates) {
            for (int i = 0; x; i++) {
                if (x & 1) cnt[i]++;
                x >>= 1;
            }
        }
        int res = 0;
        for (int &i: cnt) {
            res = max(res, i);
        }
        return res;
    }
};