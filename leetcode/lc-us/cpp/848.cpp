#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int> &shifts) {
        int n = (int) shifts.size();
        vector<long> prefix_sum(n);
        prefix_sum[n - 1] = shifts[n - 1];
        for (int i = n - 2; i >= 0; i--) prefix_sum[i] += prefix_sum[i + 1] + shifts[i];
        for (int i = 0; i < n; i++) {
            long acsii = (long) s[i] + prefix_sum[i] % 26;
            acsii -= 'a';
            acsii %= 26;
            s[i] = 'a' + acsii;
        }
        return s;
    }
};