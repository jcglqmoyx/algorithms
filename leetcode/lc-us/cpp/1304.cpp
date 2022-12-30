#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        int high = n / 2, low = -high;
        for (int i = 0; i < n; i += 2) {
            res[i] = high--;
            if (i + 1 < n) {
                res[i + 1] = low++;
            }
        }
        return res;
    }
};