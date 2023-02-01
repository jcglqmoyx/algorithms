#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getXORSum(vector<int> &arr1, vector<int> &arr2) {
        auto f = [](vector<int> &v) {
            int res = 0;
            for (int x: v) res ^= x;
            return res;
        };
        return f(arr1) & f(arr2);
    }
};