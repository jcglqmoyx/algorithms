#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res(s.size());
        int low = 0, high;
        while (s[low] != c) {
            low++;
        }
        high = low;
        for (int i = 0; i < s.size(); i++) {
            if (i >= high) {
                low = high;
                int j = high + 1;
                while (j < s.size() && s[j] != c) {
                    j++;
                }
                if (j < s.size()) {
                    high = j;
                }
            }
            res[i] = min(abs(low - i), abs(high - i));
        }
        return res;
    }
};