#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> expand(string s) {
        vector<string> res = {""};
        int n = (int) s.size();
        for (int i = 0; i < n; i++) {
            if (isalpha(s[i])) {
                for (string &str: res) {
                    str.push_back(s[i]);
                }
            } else {
                i++;
                int j = i;
                while (j < n && s[j] != '}') j++;
                vector<string> tmp;
                tmp.reserve(res.size());
                for (int k = i; k < j; k += 2) {
                    for (string &str: res) {
                        tmp.push_back(str + s[k]);
                    }
                }
                res = tmp;
                i = j;
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};