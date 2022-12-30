#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        long long cur = rowIndex;
        for (int i = 1; i <= rowIndex; i++) {
            res[i] = (int) cur;
            cur = cur * (rowIndex - i) / (i + 1);
        }
        return res;
    }
};