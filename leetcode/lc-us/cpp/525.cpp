#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> map;
        int count = 0;
        int max_len = 0;
        map[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            count += nums[i] ? 1 : -1;
            if (map.count(count)) {
                max_len = max(max_len, i - map[count]);
            }
            if (map.find(count) == map.end()) {
                map[count] = i;
            }
        }
        return max_len;
    }
};