#include <bits/stdc++.h>

using namespace std;

class Solution {
    long get_id(long num, long mod) {
        return num >= 0 ? num / mod : (num + 1) / mod - 1;
    }

public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        unordered_map<long, long> bucket;
        long mod = (long) t + 1;
        for (int i = 0; i < nums.size(); i++) {
            long id = get_id(nums[i], mod);
            if (bucket.find(id) != bucket.end()) return true;
            if (bucket.count(id - 1) && abs(bucket[id - 1] - nums[i]) <= t) return true;
            if (bucket.count(id + 1) && abs(bucket[id + 1] - nums[i]) <= t) return true;
            bucket[id] = nums[i];
            if (bucket.size() > k) bucket.erase(get_id(nums[i - k], mod));
        }
        return false;
    }
};