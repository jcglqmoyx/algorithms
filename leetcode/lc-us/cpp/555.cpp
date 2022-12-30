#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string splitLoopedString(vector<string> &strs) {
        string();
        for (string &str: strs) {
            int n = (int) str.size();
            int l = 0, r = n - 1;
            bool flag = false;
            while (l < r) {
                if (str[l] < str[r]) {
                    flag = true;
                    break;
                } else if (str[l] > str[r]) break;
                l++, r--;
            }
            if (flag) reverse(str.begin(), str.end());
        }
        int n = (int) strs.size();
        string res;
        for (int i = 0; i < n; i++) {
            string before, after;
            for (int j = 0; j < i; j++) before += strs[j];
            for (int j = i + 1; j < n; j++) after += strs[j];
            reverse(strs[i].begin(), strs[i].end());
            for (int j = 0; j < strs[i].size(); j++) {
                string s = strs[i].substr(j) + after + before + strs[i].substr(0, j);
                res = max(res, s);
            }
            reverse(strs[i].begin(), strs[i].end());
            for (int j = 0; j < strs[i].size(); j++) {
                string s = strs[i].substr(j) + after + before + strs[i].substr(0, j);
                res = max(res, s);
            }
        }
        return res;
    }
};