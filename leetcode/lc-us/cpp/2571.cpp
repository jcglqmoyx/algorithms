#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(int n) {
        return __builtin_popcount(3 * n ^ n);
    }
};