#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        const int N = 100010;
        int n = (int) word.size();
        int s[N][10];
        int cnt[1024] = {1};
        memset(s, 0, sizeof s);
        long long res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                s[i][j] += s[i - 1][j];
                if (word[i - 1] - 'a' == j) s[i][j]++;
            }
            int state = 0;
            for (int j = 0; j < 10; j++) {
                state = state * 2 + s[i][j] % 2;
            }
            res += cnt[state];
            for (int j = 0; j < 10; j++) {
                res += cnt[state ^ (1 << j)];
            }
            cnt[state]++;
        }
        return res;
    }
};