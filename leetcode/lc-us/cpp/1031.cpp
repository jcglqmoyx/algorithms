#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {
        int n = (int) nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        int res = 0;
        for (int i = 1; i + firstLen - 1 <= n; i++) {
            for (int j = i + firstLen; j + secondLen - 1 <= n; j++) {
                res = max(res, s[i + firstLen - 1] - s[i - 1] + s[j + secondLen - 1] - s[j - 1]);
            }
        }
        for (int i = 1; i + secondLen - 1 <= n; i++) {
            for (int j = i + secondLen; j + firstLen - 1 <= n; j++) {
                res = max(res, s[i + secondLen - 1] - s[i - 1] + s[j + firstLen - 1] - s[j - 1]);
            }
        }
        return res;
    }
};