#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        index = min(index + 1, n - index);
        long long l = 1, r = maxSum;
        while (l < r) {
            long long mid = l + (r - l + 1) / 2;
            long long left, right;
            if (mid >= index) left = (mid + (mid - index) + 1) * index / 2;
            else left = (mid + 1) * mid / 2 + index - mid;
            if (n - index >= mid - 1) right = (mid - 1) * mid / 2 + n - index - mid + 1;
            else right = ((((mid - 1) << 1) - (n - index - 1))) * (n - index) / 2;
            if (left + right <= maxSum) l = mid;
            else r = mid - 1;
        }
        return (int) l;
    }
};