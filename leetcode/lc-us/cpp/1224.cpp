#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxEqualFreq(vector<int> &nums) {
        unordered_map<int, int> m1;
        map<int, int> m2;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            m1[nums[i]]++;
            if (m1.size() == 1) {
                res = max(res, m1.begin()->second);
            }
            int t = m1[nums[i]];
            m2[t]++;
            if (t - 1) {
                m2[t - 1]--;
                if (!m2[t - 1]) {
                    m2.erase(t - 1);
                }
            }
            if (m2.size() == 1 && m2.rbegin()->first == 1) {
                res = max(res, i + 1);
            }
            if (m2.size() == 2) {
                if (m2.rbegin()->second == 1 && m2.rbegin()->first - m2.begin()->first == 1) {
                    res = i + 1;
                }
                if (m2.begin()->second == 1 && m2.begin()->first == 1) {
                    res = i + 1;
                }
            }
        }
        return res;
    }
};