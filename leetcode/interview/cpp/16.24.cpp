#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> pairSums(vector<int> &nums, int target) {
        vector<vector<int>> pairs;
        if (nums.size() < 2) return pairs;
        unordered_map<int, int> map;
        for (int num: nums) {
            if (map.count(target - num)) {
                pairs.push_back({num, target - num});
                if (map[target - num] == 1) {
                    map.erase(target - num);
                } else {
                    map[target - num]--;
                }
            } else {
                map[num]++;
            }
        }
        return pairs;
    }
};