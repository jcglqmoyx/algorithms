#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        return (int) (sqrt((double) n * 2 + 0.25) - 0.5);
    }
};