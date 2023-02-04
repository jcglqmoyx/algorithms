#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeWin(vector<int> &prizePositions, int k) {
        int n = (int) prizePositions.size(), res = 0, f[n];
        for (int l = 0, r = 0; r < n; r++) {
            while (prizePositions[r] - prizePositions[l] > k) l++;
            f[r] = r - l + 1;
            int t = f[r];
            if (l) t += f[l - 1];
            res = max(res, t);
            if (r) f[r] = max(f[r], f[r - 1]);
        }
        return res;
    }
};