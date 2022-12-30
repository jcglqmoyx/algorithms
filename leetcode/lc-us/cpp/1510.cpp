#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        bitset<100005> b;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!b[i - j * j]) {
                    b[i] = true;
                    break;
                }
            }
        }
        return b[n];
    }
};