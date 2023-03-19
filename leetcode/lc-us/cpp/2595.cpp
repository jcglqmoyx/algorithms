#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> evenOddBit(int n) {
        vector<int> res(2);
        int i = 0;
        while (n) {
            if (n & 1) res[i & 1]++;
            i++, n >>= 1;
        }
        return res;
    }
};