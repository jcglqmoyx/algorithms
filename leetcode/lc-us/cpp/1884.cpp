#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int twoEggDrop(int n) {
        return ceil((-1.0 + sqrt(n * 8 + 1)) / 2);
    }
};