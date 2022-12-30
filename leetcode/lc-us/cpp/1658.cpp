#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int size = (int) nums.size(), INF = 1e9;
        for (int i = 0; i < size; i++) nums.push_back(nums[i]);
        int n = (int) nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int res = INF;
        for (int i = 1; i <= size; i++) {
            int l = i, r = i + size - 1;
            while (l < r) {
                int mid = (l + r) / 2;
                int sum = s[mid] - s[i - 1];
                if (sum < x) l = mid + 1;
                else r = mid;
            }
            if (s[l] - s[i - 1] == x && (l >= size || i == 1)) {
                res = min(res, l - i + 1);
            }
        }
        return res == INF ? -1 : res;
    }
};