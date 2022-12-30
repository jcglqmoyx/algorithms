#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        vector<int> res(2);
        unordered_set<int> S;
        for (int x: nums) {
            if (S.count(x)) {
                S.erase(x);
                res[0]++;
            } else {
                S.insert(x);
            }
        }
        res[1] = (int) nums.size() - res[0] * 2;
        return res;
    }
};