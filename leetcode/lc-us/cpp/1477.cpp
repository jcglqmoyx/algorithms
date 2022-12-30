#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int> &arr, int target) {
        const int INF = 0x3f3f3f3f;
        int n = (int) arr.size();
        int f[n];
        memset(f, 0x3f, sizeof f);
        int res = INF;
        for (int i = 0, j = 0, sum = 0; i < n; i++) {
            sum += arr[i];
            while (sum > target) sum -= arr[j++];
            if (sum == target) {
                if (j) res = min(res, f[j - 1] + i - j + 1);
                f[i] = min(f[i], i - j + 1);
            }
            if (i) f[i] = min(f[i], f[i - 1]);
        }
        return res > n ? -1 : res;
    }
};