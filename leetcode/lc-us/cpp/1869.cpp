#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0, zero = 0;
        int o = 0, z = 0;
        for (char c: s) {
            if (c == '0') {
                z++;
                zero = max(zero, z);
                o = 0;
            } else {
                o++;
                one = max(one, o);
                z = 0;
            }
        }
        return one > zero;
    }
};