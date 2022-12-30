#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        auto left = beautifulArray((n + 1) / 2);
        auto right = beautifulArray(n / 2);
        vector<int> res;
        res.reserve(left.size() + right.size());
        for (int x: left) res.push_back(x * 2 - 1);
        for (int x: right) res.push_back(x * 2);
        return res;
    }
};