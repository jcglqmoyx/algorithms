#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximizeGreatness(vector<int> &nums) {
        multiset<int> s;
        for (int x: nums) s.insert(x);
        int res = 0;
        for (int x: nums) {
            auto it = s.upper_bound(x);
            if (it == s.end()) continue;
            s.erase(it);
            res++;
        }
        return res;
    }
};
