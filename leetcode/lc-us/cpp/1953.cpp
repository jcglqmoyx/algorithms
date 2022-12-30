#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int> &milestones) {
        using LL = long long;
        int mx = *max_element(milestones.begin(), milestones.end());
        LL sum = 0;
        for (int m: milestones) sum += m;
        LL left = sum - mx;
        if (left >= mx) return sum;
        else return left * 2 + 1;
    }
};