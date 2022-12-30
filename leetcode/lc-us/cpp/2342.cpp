#include <bits/stdc++.h>

using namespace std;

class Solution {
    int get_sum(int x) {
        int res = 0;
        while (x) {
            res += x % 10;
            x /= 10;
        }
        return res;
    }

public:
    int maximumSum(vector<int> &nums) {
        unordered_map<int, int> S;
        int res = -1;
        for (int x: nums) {
            int sum = get_sum(x);
            if (S.count(sum)) {
                res = max(res, x + S[sum]);
                S[sum] = max(S[sum], x);
            } else {
                S[sum] = x;
            }
        }
        return res;
    }
};