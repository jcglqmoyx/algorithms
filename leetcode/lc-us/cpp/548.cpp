#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool splitArray(vector<int> &nums) {
        int n = (int) nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + nums[i - 1];
        }
        for (int i = 4; i + 3 <= n; i++) {
            unordered_set<int> S;
            for (int j = 2; j < i - 1; j++) {
                if (s[j - 1] == s[i - 1] - s[j]) {
                    S.insert(s[j - 1]);
                }
            }
            for (int j = i + 2; j + 1 <= n; j++) {
                if (s[j - 1] - s[i] == s[n] - s[j]) {
                    if (S.count(s[j - 1] - s[i])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};