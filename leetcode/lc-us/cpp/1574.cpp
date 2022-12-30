#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int n = (int) arr.size();
        int l = 1, r = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) {
                l++;
            } else {
                break;
            }
        }
        if (l == n) return 0;
        for (int i = n - 2; ~i; i--) {
            if (arr[i] <= arr[i + 1]) {
                r++;
            } else {
                break;
            }
        }
        int res = n - r;
        for (int i = 0; i < l; i++) {
            int p = (int) (lower_bound(arr.begin() + n - r, arr.end(), arr[i]) - arr.begin());
            res = min(res, p + -i - 1);
        }
        return res;
    }
};