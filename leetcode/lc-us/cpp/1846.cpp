#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i + 1] - arr[i] > 1) {
                arr[i + 1] = arr[i] + 1;
            }
        }
        int res = arr.back() - arr.front() + 1;
        if (arr.back() > arr.size()) res = max(res, (int) arr.size());
        return res;
    }
};