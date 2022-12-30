#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> constructArr(vector<int> &a) {
        if (a.size() < 2) return a;
        int n = a.size();
        vector<int> res(n), left(a), right(a);
        for (int i = 1; i < n; i++) {
            left[i] *= left[i - 1];
            right[n - i - 1] *= right[n - i];
        }
        res.front() = right[1];
        res.back() = left[n - 2];
        for (int i = 1; i < n - 1; i++) {
            res[i] = left[i - 1] * right[i + 1];
        }
        return res;
    }
};