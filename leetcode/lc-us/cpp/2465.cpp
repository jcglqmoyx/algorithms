#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int distinctAverages(vector<int> &nums) {
        unordered_set<double> S;
        sort(nums.begin(), nums.end());
        int n = (int) nums.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            S.insert((nums[i] + nums[j]) / 2.0);
        }
        return (int) S.size();
    }
};