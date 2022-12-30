#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int> &arr1, vector<int> &arr2) {
        int n = (int) arr1.size();
        int mx1 = -1e9, mx2 = -1e9, mx3 = -1e9, mx4 = -1e9, mn1 = 1e9, mn2 = 1e9, mn3 = 1e9, mn4 = 1e9;
        for (int i = 0; i < n; i++) {
            int a = arr1[i] + arr2[i] + i;
            int b = arr1[i] - arr2[i] + i;
            int c = arr2[i] - arr1[i] + i;
            int d = i - arr1[i] - arr2[i];
            mx1 = max(mx1, a);
            mn1 = min(mn1, a);
            mx2 = max(mx2, b);
            mn2 = min(mn2, b);
            mx3 = max(mx3, c);
            mn3 = min(mn3, c);
            mx4 = max(mx4, d);
            mn4 = min(mn4, d);
        }
        return max(max(mx1 - mn1, mx2 - mn2), max(mx3 - mn3, mx4 - mn4));
    }
};