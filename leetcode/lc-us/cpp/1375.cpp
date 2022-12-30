#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int> &light) {
        int mx = 0, res = 0;
        for (int i = 0; i < light.size(); i++) {
            mx = max(mx, light[i]);
            if (mx == i + 1) res++;
        }
        return res;
    }
};