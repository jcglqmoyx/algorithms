#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        int i = 0;
        for (; i < n - k - 1; i++) {
            res[i] = i + 1;
        }
        int p = n - k, q = n;
        while (i < n) {
            res[i++] = p++;
            if (i < n) res[i++] = q--;
        }
        return res;
    }
};