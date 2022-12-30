#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int res = 0;
        int sum = 0;
        unordered_set<int> s;
        int i = 0;
        for (int x: nums) {
            if (s.count(x)) {
                while (s.count(x)) {
                    s.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }
            }
            sum += x;
            res = max(res, sum);
            s.insert(x);
        }
        return res;
    }
};