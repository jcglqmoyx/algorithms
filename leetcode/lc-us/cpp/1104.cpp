#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int row = 1, left_most = 1;
        while (left_most * 2 <= label) {
            row++;
            left_most <<= 1;
        }
        res.push_back(label);
        if (row % 2 == 0) label = reversed(label, row);
        while (label > 1) {
            label >>= 1;
            int tmp = label;
            row--;
            if (row % 2 == 0) label = reversed(label, row);
            res.push_back(label);
            if (row % 2 == 0) label = tmp;
        }
        reverse(res.begin(), res.end());
        return res;
    }

private:
    static int reversed(int label, int row) {
        int left_most = 1 << (row - 1);
        return left_most * 3 - 1 - label;
    }
};