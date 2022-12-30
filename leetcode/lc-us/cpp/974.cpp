#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int> &nums, int k) {
        int cnt = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            int r = sum % k;
            if (r < 0) r += k;
            if (map.count(r)) {
                cnt += map[r];
            }
            map[r]++;
        }
        return cnt;
    }
};