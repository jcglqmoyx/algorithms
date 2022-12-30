#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int houseOfCards(int n) {
        int f[n + 1];
        memset(f, 0, sizeof f);
        f[0] = 1;
        for (int i = 2; i <= n; i += 3) {
            for (int j = n; j >= i; j--) {
                f[j] += f[j - i];
            }
        }
        return f[n];
    }
};