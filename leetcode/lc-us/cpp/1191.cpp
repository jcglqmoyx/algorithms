#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        const int MOD = 1e9 + 7;
        n = (int) arr.size();
        LL res = max(0LL, get(arr));
        if (k == 1) return (int) res;
        vector<int> nums = arr;
        for (int i = 0; i < n - 1; i++) nums.push_back(arr[i]);
        res = max(res, get(nums));
        vector<LL> r(n), l(n);
        LL sum = arr[0];
        l[0] = arr[0], r[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) {
            sum += arr[i];
            l[i] = max(l[i - 1], sum);
        }
        sum = arr[n - 1];
        for (int i = n - 2; ~i; i--) {
            sum += arr[i];
            r[i] = max(r[i + 1], sum);
        }
        sum = accumulate(arr.begin(), arr.end(), 0);
        res = max(res, (k - 2) * sum + l[n - 1] + r[0]);
        res %= MOD;
        return (int) res;
    }

private:
    int n;
    using LL = long long;

    static LL get(vector<int> &arr) {
        int sum = 0, res = -1e9;
        for (int x: arr) {
            if (sum + x <= x) sum = x;
            else sum += x;
            res = max(res, sum);
        }
        return res;
    }
};