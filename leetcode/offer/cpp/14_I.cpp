#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3) return n - 1;
        int quotient = n / 3;
        int mod = n % 3;
        if (mod == 0) {
            return (int) pow(3, quotient);
        } else if (mod == 1) {
            return (int) pow(3, quotient - 1) * 4;
        } else {
            return (int) pow(3, quotient) * 2;
        }
    }
};