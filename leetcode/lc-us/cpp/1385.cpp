#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        int res = 0;
        arr2.push_back(INT32_MIN / 2), arr2.push_back(INT32_MAX / 2);
        sort(arr2.begin(), arr2.end());
        for (int x: arr1) {
            auto l = lower_bound(arr2.begin(), arr2.end(), x);
            if (*l - x <= d) continue;
            l--;
            if (x - *l <= d) continue;
            res++;
        }
        return res;
    }
};