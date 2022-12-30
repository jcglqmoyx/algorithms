#include <bits/stdc++.h>

using namespace std;

const int N = 10005;

int cnt[N], f[N][2];

class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        memset(cnt, 0, sizeof cnt);
        memset(f, 0, sizeof f);
        for (int num: nums) cnt[num]++;
        for (int i = 1; i < N; i++) {
            int p = i * cnt[i];
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][0] + p;
        }
        return max(f[N - 1][0], f[N - 1][1]);
    }
};