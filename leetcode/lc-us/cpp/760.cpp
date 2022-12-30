#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size();
        vector<int> res(n);
        int map[100001] = {0};
        for (int i = 0; i < n; i++) {
            map[nums2[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            res[i] = map[nums1[i]];
        }
        return res;
    }
};