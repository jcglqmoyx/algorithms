#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumDivThree(vector<int> &nums) {
        int sum = 0;
        vector<int> one, two;
        for (int x: nums) {
            int r = x % 3;
            sum += x;
            if (r == 1) one.push_back(x);
            else if (r == 2) two.push_back(x);
        }
        sort(one.begin(), one.end());
        sort(two.begin(), two.end());
        int res = 0;
        int r = sum % 3;
        if (r == 0) res = sum;
        else if (r == 1) {
            if (!one.empty()) {
                res = max(res, sum - one[0]);
            }
            if (two.size() >= 2) {
                res = max(res, sum - two[0] - two[1]);
            }
        } else {
            if (one.size() >= 2) {
                res = max(res, sum - one[0] - one[1]);
            }
            if (!two.empty()) {
                res = max(res, sum - two[0]);
            }
        }
        return res;
    }
};