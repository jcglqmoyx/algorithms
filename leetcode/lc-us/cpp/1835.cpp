#include <bits/stdc++.h>

using namespace std;

class Solution {
    int xor_sum(vector<int> &a) {
        int res = 0;
        for (int x: a) res ^= x;
        return res;
    }

public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        return xor_sum(arr1) & xor_sum(arr2);
    }
};