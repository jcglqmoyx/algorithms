#include <bits/stdc++.h>

using namespace std;

class Solution {
    using LL = long long;

    int f[16];
    unordered_map<int, int> M;

    void init() {
        M = {{0, 0},
             {1, 1},
             {6, 9},
             {8, 8},
             {9, 6}};
        memset(f, 0, sizeof f);
        f[1] = 3;
        for (int i = 2; i < 16; i++) {
            int t = 4;
            for (int j = 1; j < i >> 1; j++) t *= 5;
            if (i & 1) t *= 3;
            f[i] = t;
        }
    }

    int calc(int n, int x) {
        if (n == 1) {
            if (x == 0 || x == 1 || x == 8) return 1;
            return 0;
        }
        if (n == 2) return 1;
        n -= 2;
        int res = 1;
        for (int i = 0; i < n >> 1; i++) res *= 5;
        if (n & 1) res *= 3;
        return res;
    }

    bool check(vector<int> &nums) {
        vector<int> t = nums;
        int n = (int) nums.size();
        for (int i = 0, j = n - 1; i <= j; i++, j--) {
            if (!M.count(t[j])) return false;
            t[i] = M[t[j]];
        }
        reverse(nums.begin(), nums.end());
        reverse(t.begin(), t.end());
        return t <= nums;
    }

    int get(LL n) {
        if (n < 1) return 1;
        if (n < 8) return 2;
        if (n < 10) return 3;
        vector<int> nums;
        while (n) nums.push_back((int) (n % 10)), n /= 10;
        int res = 0;
        int m = (int) nums.size();
        for (int i = m - 1; i >= m >> 1; i--) {
            int x = nums[i];
            for (int j = 0; j < x; j++) {
                if (!M.count(j) || i == m - 1 && !j) continue;
                res += calc(m - (m - i - 1) * 2, j);
            }
            if (!M.count(x)) break;
        }
        for (int i = 1; i < m; i++) res += f[i];
        if (check(nums)) res++;
        return res;
    }

public:
    int strobogrammaticInRange(string low, string high) {
        init();
        LL l = stoll(low), r = stoll(high);
        int res = get(r);
        if (l) res -= get(l - 1);
        return res;
    }
};