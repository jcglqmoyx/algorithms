#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLHS(vector<int> &nums) {
        int longest_harmonious_subsequence = 0;
        unordered_map<int, int> map;
        for (int num: nums) {
            map[num]++;
        }
        for (auto x: map) {
            int len = x.second;
            int a = 0, b = 0;
            if (map.count((x.first - 1))) {
                a = len + map[x.first - 1];
            }
            if (map.count(x.first + 1)) {
                b = len + map[x.first + 1];
            }
            longest_harmonious_subsequence = max(longest_harmonious_subsequence, max(a, b));
        }
        return longest_harmonious_subsequence;
    }
};