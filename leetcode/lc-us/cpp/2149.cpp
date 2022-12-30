#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> res(n);
        int i = 0, j = 1;
        for (int x: nums) {
            if (x > 0) res[i] = x, i += 2;
            else res[j] = x, j += 2;
        }
        return res;
    }
};