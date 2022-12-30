#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> s;
        for (int x: nums) s.insert(x);
        int res = 0;
        for (int x: s) {
            if (s.count(x - 1)) continue;
            int y = x + 1;
            while (s.count(y)) y++;
            res = max(res, y - x);
        }
        return res;
    }
};