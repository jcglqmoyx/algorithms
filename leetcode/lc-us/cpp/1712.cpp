#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int waysToSplit(vector<int> &nums) {
        const int MOD = 1e9 + 7;
        n = (int) nums.size(), s.resize(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int res = 0;
        for (int i = 1; i <= n - 2; i++) {
            int cnt = calc(i);
            res = (res + cnt) % MOD;
        }
        return res;
    }

private:
    int n;
    vector<int> s;

    inline int calc(int idx) {
        int first = s[idx];
        if (first * 2 > s[n] - first) return 0;
        int l = idx + 1, r = n - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            int second = s[mid] - first;
            if (second < first) l = mid + 1;
            else r = mid;
        }
        int second = s[l] - first, third = s[n] - s[l];
        if (first > second || second > third) return 0;
        int low = l;
        l = low, r = n - 1;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            second = s[mid] - first, third = s[n] - s[mid];
            if (second <= third) l = mid;
            else r = mid - 1;
        }
        return r - low + 1;
    }
};