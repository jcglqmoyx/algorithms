#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        int res = 1e9, cnt = -1;
        for (int d: divisors) {
            int t = 0;
            for (int x: nums) {
                if (x % d == 0) t++;
            }
            if (t > cnt || t == cnt && d < res) res = d, cnt = t;
        }
        return res;
    }
};