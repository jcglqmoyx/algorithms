#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        k = min(k, (int) num.size());
        for (char c: num) {
            while (k && !res.empty() && res.back() > c) res.pop_back(), k--;
            res.push_back(c);
        }
        while (k--) res.pop_back();
        int i = 0;
        while (i < res.size() && res[i] == '0') i++;
        return i == res.size() ? "0" : res.substr(i);
    }
};