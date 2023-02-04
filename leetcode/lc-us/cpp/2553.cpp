#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int> &nums) {
        vector<int> res;
        for (int x: nums) {
            for (char c: to_string(x)) {
                res.push_back(c - '0');
            }
        }
        return res;
    }
};