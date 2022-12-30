#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string res;
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            int len = (int) res.size();
            if (len >= 2 && res[len - 2] == s[i] && res[len - 1] == s[i]) {
                int j = i + 1;
                while (j < n && s[j] == res.back()) j++;
                i = j - 1;
                continue;
            }
            res.push_back(s[i]);
        }
        return res;
    }
};