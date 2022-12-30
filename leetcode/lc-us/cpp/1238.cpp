#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        int m = 1 << n;
        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            res[i] = start ^ i ^ (i >> 1);
        }
        return res;
    }
};