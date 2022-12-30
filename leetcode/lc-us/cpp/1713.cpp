#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &target, vector<int> &arr) {
        unordered_map<int, int> hash;
        for (int i = 0; i < target.size(); i++) hash[target[i]] = i;
        vector<int> v;
        for (int num: arr) {
            if (!hash.count(num)) continue;
            int idx = hash[num];
            if (v.empty() || v.back() < idx) v.push_back(idx);
            else {
                auto pos = lower_bound(v.begin(), v.end(), idx);
                *pos = idx;
            }
        }
        return (int) (target.size() - v.size());
    }
};