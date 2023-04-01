#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        int cnt[10]{};
        int mn1 = 10, mn2 = 10;
        for (int x: nums1) cnt[x]++, mn1 = min(mn1, x);
        for (int x: nums2) cnt[x]++, mn2 = min(mn2, x);
        for (int i = 1; i <= 9; i++) {
            if (cnt[i] == 2) return i;
        }
        if (mn1 > mn2) swap(mn1, mn2);
        return mn1 * 10 + mn2;
    }
};