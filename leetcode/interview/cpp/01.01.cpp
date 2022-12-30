#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isUnique(string astr) {
        int mask = 0;
        for (char c: astr) {
            int bit = 1 << (c - 'a');
            if (bit & mask) return false;
            else mask |= bit;
        }
        return true;
    }
};