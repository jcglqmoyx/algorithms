#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fixedPoint(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid > arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return low < n && arr[low] == low ? low : -1;
    }
};