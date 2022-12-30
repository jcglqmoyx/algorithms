#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double l = *min_element(nums.begin(), nums.end()), r = *max_element(nums.begin(), nums.end());
        while (fabs(l - r) > 1e-6) {
            double mid = (l + r) / 2;
            if (check(nums, k, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }

private:
    bool check(vector<int> &nums, int k, double m) {
        double prev = 0, min_sum = 0, sum = 0;
        for (int i = 0; i < k; i++) {
            sum += nums[i] - m;
        }
        if (sum >= 0) {
            return true;
        }
        for (int i = k; i < nums.size(); i++) {
            sum += nums[i] - m;
            prev += nums[i - k] - m;
            min_sum = min(min_sum, prev);
            if (sum >= min_sum) {
                return true;
            }
        }
        return false;
    }
};