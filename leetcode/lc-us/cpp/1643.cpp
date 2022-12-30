#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string kthSmallestPath(vector<int> &destination, int k) {
        string res;
        int v = destination[0], h = destination[1];
        long long C[v + h + 1][v + h + 1];
        memset(C, 0, sizeof C);
        for (int i = 1; i <= v + h; i++) {
            for (int j = 0; j <= i; j++) {
                if (!j) {
                    C[i][j] = 1;
                } else if (i) {
                    if (j > i - j) C[i][j] = C[i][i - j];
                    else C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
                }
            }
        }
        for (int tot = v + h; res.size() < tot;) {
            if (!h) res.push_back('V'), v--;
            else if (!v) res.push_back('H'), h--;
            else {
                long long first = C[v + h - 1][h - 1];
                if (first >= k) {
                    res.push_back('H');
                    h--;
                } else {
                    res.push_back('V');
                    v--;
                    k -= (int) first;
                }
            }
        }
        return res;
    }
};