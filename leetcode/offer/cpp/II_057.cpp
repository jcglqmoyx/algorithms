#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        set<pair<long long, int>> s;
        for (int i = 0, j = 0; j < nums.size(); j++) {
            auto p = s.lower_bound({nums[j], j});
            if (p != s.end() && abs(p->first - nums[j]) <= t && abs(p->second - j) <= k) return true;
            if (p != s.begin()) {
                auto q = p;
                q--;
                if (abs(q->first - nums[j]) <= t && abs(q->second - j) <= k) return true;
            }
            s.insert({nums[j], j});
            if (j - i + 1 > k) s.erase({nums[i], i});
        }
        return false;
    }
};