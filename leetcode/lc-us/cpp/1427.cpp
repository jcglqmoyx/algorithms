#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>> &shift) {
        int k = 0;
        for (auto &v: shift) {
            if (v[0] == 0) k -= v[1];
            else k += v[1];
        }
        int n = (int) s.size();
        k %= n;
        if (k < 0) k += n;
        return s.substr(n - k) + s.substr(0, n - k);

    }
};