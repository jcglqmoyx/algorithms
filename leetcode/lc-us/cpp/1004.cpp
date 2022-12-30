#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int res = 0;
        int left = 0;
        int cnt[2] = {};
        for (int right = 0; right < A.size(); right++) {
            if (A[right] == 1) {
                cnt[1]++;
            } else {
                cnt[0]++;
                while (cnt[0] > K) {
                    cnt[A[left++]]--;
                }
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};