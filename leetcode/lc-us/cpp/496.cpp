#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = (int) nums1.size(), m = (int) nums2.size();
        unordered_map<int, int> hash;
        stack<int> stk;
        for (int i = m - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums2[i]) stk.pop();
            if (!stk.empty()) hash[nums2[i]] = stk.top();
            else hash[nums2[i]] = -1;
            stk.push(nums2[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            res[i] = hash[nums1[i]];
        }
        return res;
    }
};