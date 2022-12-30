#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int> &left, vector<int> &right) {
        int x = 0, y = n;
        if (!left.empty()) x = *max_element(left.begin(), left.end());
        if (!right.empty()) y = *min_element(right.begin(), right.end());
        return max(x, n - y);
    }
};