#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &colors) {
        int n = (int) colors.size();
        int l = colors[0], r = colors[n - 1];
        if (l != r) return n - 1;
        int res = 0;
        for (int i = n - 1; i >= 1; i--) {
            if (colors[i] != l) {
                res = max(res, i);
                break;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            if (colors[i] != r) {
                res = max(res, n - 1 - i);
                break;
            }
        }
        return res;
    }
};