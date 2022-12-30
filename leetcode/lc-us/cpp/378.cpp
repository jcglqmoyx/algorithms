#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        long l = INT32_MIN, r = INT32_MAX;
        while (l < r) {
            int cnt = 0;
            long mid = l + (r - l) / 2;
            int i = (int) matrix[0].size() - 1;
            for (auto &j: matrix) {
                while (i >= 0 && j[i] > mid) i--;
                cnt += i + 1;
            }
            if (cnt >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) l;
    }
};