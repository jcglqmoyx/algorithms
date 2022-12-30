#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> mostCompetitive(vector<int> &nums, int k) {
        vector<int> res;
        int n = (int) nums.size(), cnt = n - k;
        for (int x: nums) {
            while (!res.empty() && res.back() > x && cnt) {
                res.pop_back();
                cnt--;
            }
            res.push_back(x);
        }
        while (res.size() > k) res.pop_back();
        return res;
    }
};