#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        unordered_set<int> S;
        for (int x: nums) S.insert(x);
        while (S.count(original)) {
            original <<= 1;
        }
        return original;
    }
};