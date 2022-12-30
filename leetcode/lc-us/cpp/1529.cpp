#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minFlips(string target) {
        int n = (int) target.size(), flips = 0;
        if (target[0] == '1') flips++;
        for (int i = 1; i < n; i++) {
            if (target[i] != target[i - 1]) {
                flips++;
            }
        }
        return flips;
    }
};