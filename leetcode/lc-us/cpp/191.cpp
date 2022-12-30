#include <bits/stdc++.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int hamming_weight = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1) {
                hamming_weight++;
            }
            n >>= 1;
        }
        return hamming_weight;
    }
};