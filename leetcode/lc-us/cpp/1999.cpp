#include <bits/stdc++.h>

using namespace std;

class Solution {
    const long long INF = 0x8fffffff;
    long long res = INF;

    void dfs(int k, int digit1, int digit2, long long num) {
        if (num >= res) return;
        if (num > k && num % k == 0) {
            res = min(res, num);
            return;
        }
        if (num == 0) {
            if (digit1) {
                dfs(k, digit1, digit2, num * 10 + digit1);
            }
            if (digit2) {
                dfs(k, digit1, digit2, num * 10 + digit2);
            }
        } else {
            dfs(k, digit1, digit2, num * 10 + digit1);
            dfs(k, digit1, digit2, num * 10 + digit2);
        }
    }

public:
    int findInteger(int k, int digit1, int digit2) {
        if (digit1 > digit2) swap(digit1, digit2);
        dfs(k, digit1, digit2, 0);
        if (res == INF) return -1;
        return (int) res;
    }
};