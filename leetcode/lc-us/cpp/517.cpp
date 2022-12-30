#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int> &machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = (int) machines.size();
        if (sum % n) return -1;
        int left = 0, right = sum;
        int avg = sum / n;
        int res = 0;
        for (int i = 0; i < n; i++) {
            right -= machines[i];
            if (i) left += machines[i - 1];
            int l = max(avg * i - left, 0), r = max(avg * (n - i - 1) - right, 0);
            res = max(res, l + r);
        }
        return res;
    }
};