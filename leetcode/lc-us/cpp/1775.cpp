#include <bits/stdc++.h>

using namespace std;

class Solution {
    int calc(vector<int> &a, int m, int s1, vector<int> &b, int n, int s2) {
        if (s1 > s2) return calc(b, n, s2, a, m, s1);
        int cnt = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<>());
        int diff = s2 - s1;
        int i = 0, j = 0;
        while (diff > 0) {
            for (int minus = 1; minus <= 5 && diff > 0; minus++) {
                while (i < m && a[i] == minus) {
                    diff -= (6 - minus);
                    cnt++, i++;
                    if (diff <= 0) break;
                }
                if (diff <= 0) break;
                while (j < n && b[j] == 7 - minus) {
                    diff -= (6 - minus);
                    cnt++, j++;
                    if (diff <= 0) break;
                }
            }
        }
        return cnt;
    }

public:
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        int s1 = accumulate(nums1.begin(), nums1.end(), 0), s2 = accumulate(nums2.begin(), nums2.end(), 0);
        int m = (int) nums1.size(), n = (int) nums2.size();
        if (m * 6 < n || n * 6 < m) return -1;
        if (s1 == s2) return 0;
        return calc(nums1, m, s1, nums2, n, s2);
    }
};