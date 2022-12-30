#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss;
        ss << s;
        string res;
        string str;
        vector<string> strs;
        while (ss >> str) {
            strs.push_back(str);
        }
        for (int i = (int) strs.size() - 1; i >= 0; i--) res += strs[i] + ' ';
        res.pop_back();
        return res;
    }
};