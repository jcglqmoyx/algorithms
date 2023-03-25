#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int> &arr) {
        int n = (int) arr.size();
        int l = 1, r = 1;
        for (int i = 1; i < n; i++) {
            if (arr[i] >= arr[i - 1]) l++;
            else break;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] <= arr[i + 1]) r++;
            else break;
        }
        int len = max(l, r);
        for (int i = 0, j = n - r; i < l; i++) {
            while (j < n && arr[j] < arr[i]) j++;
            len = max(len, i + 1 + n - j);
        }
        return max(0, n - len);
    }
};