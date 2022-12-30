#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> recoverArray(int n, vector<int> &sums) {
        sort(sums.begin(), sums.end());
        vector<int> res;
        for (int i = n; i >= 2; i--) {
            int d = sums[1] - sums[0];
            vector<int> s, t;
            int left = 0, right = 0;
            vector<bool> st(1 << i);
            while (true) {
                while (left < 1 << i && st[left]) left++;
                if (left == (1 << i)) break;
                st[left] = true;
                s.push_back(sums[left]);
                while (st[right] || sums[left] + d != sums[right]) right++;
                t.push_back(sums[right]);
                st[right] = true;
            }
            if (find(s.begin(), s.end(), 0) != s.end()) {
                res.push_back(d);
                sums = move(s);
            } else {
                res.push_back(-d);
                sums = move(t);
            }
        }
        res.push_back(sums[0] + sums[1]);
        return res;
    }
};