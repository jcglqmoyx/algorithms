#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if (k == 0) return res;
        if (shorter == longer) return {shorter * k};
        res.reserve(k + 1);
        for (int i = 0; i < res.capacity(); i++)
            res.push_back(i * longer + (k - i) * shorter);
        return res;
    }
};