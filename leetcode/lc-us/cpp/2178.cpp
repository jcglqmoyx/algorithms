#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        using LL = long long;
        if (finalSum & 1) return {};
        vector<LL> res;
        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        if (finalSum) res.back() += finalSum;
        return res;
    }
};