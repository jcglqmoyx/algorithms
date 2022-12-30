#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int> &nums) {
        vector<int> res = {nums[0]};
        for (int i = 1; i < nums.size(); i++) {
            res.push_back(nums[i]);
            while (res.size() > 1) {
                int x = res[(int) res.size() - 2], y = res.back();
                int g = gcd(x, y);
                if (g == 1) break;
                res.pop_back();
                res.back() *= y / g;
            }
        }
        return res;
    }
};