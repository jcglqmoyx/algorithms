#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        if (a > b) swap(a, b);
        int cnt = 0;
        for (int i = 1; i * i <= a; i++) {
            if (a % i == 0) {
                if (b % i == 0) cnt++;
                if (i * i < a) {
                    if (b % (a / i) == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};