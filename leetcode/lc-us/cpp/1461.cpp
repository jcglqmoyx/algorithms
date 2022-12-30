#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = (int) s.size();
        if (n < (1 << k) + k - 1) return false;
        int num = 0;
        for (int i = 0; i < k; i++) num += (s[i] - '0') << (k - i - 1);
        unordered_set<int> nums = {num};
        for (int i = 1; i <= n - k; i++) {
            num -= (1 << (k - 1)) & num;
            num <<= 1;
            num += s[i + k - 1] - '0';
            nums.insert(num);
        }
        return nums.size() == 1 << k;
    }
};