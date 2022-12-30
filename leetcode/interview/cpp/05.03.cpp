#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverseBits(int num) {
        if (~num == 0) return 32;
        int previous = 0;
        int current = 0;
        int length = 0;
        for (int i = 0; i < 32; i++) {
            if (num & 1) {
                current++;
            } else {
                previous = current;
                current = 0;
            }
            length = max(length, previous + current + 1);
            num >>= 1;
        }
        return length;
    }
};