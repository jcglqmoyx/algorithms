#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNonOverlapping(vector<int> &nums, int target) {
        int sum = 0, last = -1, res = 0;
        unordered_map<int, int> m;
        m[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (m.count(sum - target) && m[sum - target] >= last) {
                res++;
                last = i;
            }
            m[sum] = i;
        }
        return res;
    }
};