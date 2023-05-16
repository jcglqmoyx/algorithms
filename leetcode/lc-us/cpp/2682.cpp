#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        bool st[51]{};
        for (int i = 1, x = 0;; i++) {
            if (st[x]) break;
            st[x] = true;
            x = (x + i * k) % n;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!st[i]) res.push_back(i + 1);
        }
        return res;
    }
};