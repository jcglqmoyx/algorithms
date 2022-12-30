#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int> &nums, int k) {
        int operations = 0;
        unordered_map<int, int> map;
        for (int num: nums) if (num < k) map[num]++;
        for (auto &x: map) {
            if (x.first * 2 == k) operations += map[x.first] / 2;
            else if (x.first * 2 < k && map.count(k - x.first)) operations += min(map[x.first], map[k - x.first]);
        }
        return operations;
    }
};