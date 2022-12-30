#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestNumber(string pattern) {
        string res;
        int n = (int) pattern.size();
        for (int i = 1; i <= n + 1; i++) res += to_string(i);
        for (int i = 0; i < n; i++) {
            if (pattern[i] == 'D') {
                int j = i + 1;
                while (j < n && pattern[j] == 'D') j++;
                reverse(res.begin() + i, res.begin() + j + 1);
                i = j - 1;
            }
        }
        return res;
    }
};