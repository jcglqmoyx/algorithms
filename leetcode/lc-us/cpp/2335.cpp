#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &a) {
        return max({a[0], a[1], a[2], (a[0] + a[1] + a[2] + 1) / 2});
    }
};