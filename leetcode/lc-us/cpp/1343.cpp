#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int cnt = 0;
        vector<int> s(arr.size() + 1);
        partial_sum(arr.begin(), arr.end(), s.begin() + 1);
        for (int i = 0; i <= arr.size() - k; i++) {
            if (s[i + k] - s[i] >= k * threshold) cnt++;
        }
        return cnt;
    }
};