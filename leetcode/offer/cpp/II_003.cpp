#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) {
            res[i] = res[i >> 1];
            if (i & 1) res[i]++;
        }
        return res;
    }
};