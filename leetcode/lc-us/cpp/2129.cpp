#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string s;
        string res;
        while (ss >> s) {
            int n = (int) s.size();
            if (n <= 2) {
                for (char c: s) res.push_back((char) tolower(c));
                res.push_back(' ');
            } else {
                res.push_back((char) toupper(s[0]));
                for (int i = 1; i < n; i++) {
                    res.push_back((char) tolower(s[i]));
                }
                res.push_back(' ');
            }
        }
        res.pop_back();
        return res;
    }
};