#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int> &nums) {
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        sort(nums.begin(), nums.end(), [&map](int a, int b) {
            if (map[a] != map[b]) {
                return map[a] < map[b];
            } else {
                return a > b;
            }
        });
        return nums;
    }
};