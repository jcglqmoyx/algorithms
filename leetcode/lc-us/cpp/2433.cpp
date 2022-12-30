#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int> &pref) {
        int n = (int) pref.size();
        vector<int> res(n);
        res[0] = pref[0];
        int sum = res[0];
        for (int i = 1; i < n; i++) {
            res[i] = sum ^ pref[i];
            sum ^= res[i];
        }
        return res;
    }
};