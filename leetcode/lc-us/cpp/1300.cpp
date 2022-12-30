#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int> &arr, int target) {
        int n = (int) arr.size();
        int res, min_diff = 1e9;
        sort(arr.begin(), arr.end());
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i - 1];
        for (int num = 0; num <= 1e5; num++) {
            int pos = (int) (lower_bound(arr.begin(), arr.end(), num) - arr.begin());
            int s = sum[pos] + (n - pos) * num;
            int diff = abs(s - target);
            if (diff < min_diff) min_diff = diff, res = num;
        }
        return res;
    }
};