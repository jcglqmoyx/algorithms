#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int> &encoded, int first) {
        vector<int> res;
        res.reserve(encoded.size() + 1);
        res.push_back(first);
        int prev = res.back();
        for (int x: encoded) {
            res.push_back(prev ^ x);
            prev = res.back();
        }
        return res;
    }
};