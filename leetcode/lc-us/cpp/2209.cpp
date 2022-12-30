#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = (int) floor.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (floor[i - 1] == '1');
        vector<vector<int>> f(n + 1, vector<int>(numCarpets + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= numCarpets; j++) {
                f[i][j] = max(f[i - 1][j], f[max(i - carpetLen, 0)][j - 1] + (s[i] - s[max(i - carpetLen, 0)]));
            }
        }
        return s[n] - f[n][numCarpets];
    }
};