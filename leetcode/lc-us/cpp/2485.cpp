#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int pivotInteger(int n) {
        int x = (n * n + n) >> 1;
        int st = (int) sqrt(x);
        if (st * st == x) return st;
        return -1;
    }
};