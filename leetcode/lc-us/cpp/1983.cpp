#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int widestPairOfIndices(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size();
        vector<int> s1(n + 1), s2(n + 1);
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + nums1[i - 1], s2[i] = s2[i - 1] + nums2[i - 1];
        for (int i = 1; i <= n; i++) f[i] = s1[i] -= s2[i];
        int res = 0;
        unordered_map<int, int> seen;
        for (int i = 0; i <= n; i++) {
            if (!seen.count(s1[i])) seen[s1[i]] = i;
            else res = max(res, i - seen[s1[i]]);
        }
        return res;
    }
};