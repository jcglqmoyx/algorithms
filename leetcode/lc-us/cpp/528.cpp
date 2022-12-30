#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> a, s;
public:
    Solution(vector<int> &w) {
        a = w;
        for (int &x: w) {
            if (s.empty()) s.push_back(x);
            else s.push_back(s.back() + x);
        }
    }

    int pickIndex() {
        int x = rand() % s.back() + 1;
        int l = 0, r = (int) a.size() - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (s[mid] < x) l = mid + 1;
            else r = mid;
        }
        return l;
    }
};