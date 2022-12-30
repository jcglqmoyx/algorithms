#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        init();
        return (int) c[m + n - 2][m - 1];
    }

private:
    long long c[205][205];

    void init() {
        for (int i = 0; i < 205; i++) {
            for (int j = 0; j <= i; j++) {
                if (!j) c[i][j] = 1;
                else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % INT32_MAX;
            }
        }
    }
};