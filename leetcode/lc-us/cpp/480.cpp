#include <bits/stdc++.h>

using namespace std;

class Solution {
    multiset<int> left, right;

    double get_median() {
        if (left.size() == right.size()) {
            return ((double) *left.rbegin() + *right.begin()) / 2;
        } else {
            return *right.begin();
        }
    }

public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<double> res;
        for (int i = 0; i < k; i++) {
            right.insert(nums[i]);
        }
        for (int i = 0; i < k >> 1; i++) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
        res.push_back(get_median());
        for (int i = k; i < (int) nums.size(); i++) {
            int x = nums[i - k], y = nums[i];
            if (y >= *right.begin()) {
                right.insert(y);
            } else {
                left.insert(y);
            }
            if (x >= *right.begin()) {
                right.erase(right.find(x));
            } else {
                left.erase(left.find(x));
            }
            while (int(right.size() - left.size()) > 1) {
                left.insert(*right.begin());
                right.erase(right.begin());
            }
            while (left.size() > right.size()) {
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }
            res.push_back(get_median());
        }
        return res;
    }
};