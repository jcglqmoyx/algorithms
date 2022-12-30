#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        vector<int> num;
        while (n) {
            num.push_back(n & 1);
            n >>= 1;
        }
        n = (int) num.size();
        vector<vector<int>> f(n + 1, vector<int>(2));
        f[1][1] = f[1][0] = 1;
        for (int i = 2; i <= n; i++) f[i][0] = f[i - 1][0] + f[i - 1][1], f[i][1] = f[i - 1][0];
        int res = 0;
        for (int i = n, last = 0; i; i--) {
            int x = num[i - 1];
            if (x) {
                res += f[i][0];
                if (last) return res;
            }
            last = x;
        }
        return res + 1;
    }
};