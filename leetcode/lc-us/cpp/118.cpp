#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0) return res;
        res.push_back({1});
        if (numRows == 1) return res;
        res.push_back({1, 1});
        for (int i = 3; i <= numRows; i++) {
            vector<int> row(i);
            row[0] = 1;
            for (int j = 1; j < i - 1; j++) {
                row[j] = res.back()[j - 1] + res.back()[j];
            }
            row[i - 1] = 1;
            res.push_back(row);
        }
        return res;
    }
};