#include <bits/stdc++.h>

using namespace std;

class Solution {
    bool check(string &s) {
        if (s.size() == 1) return false;
        if (s[0] != '$') return false;
        for (int i = 1; i < s.size(); i++) {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }

public:
    string discountPrices(string sentence, int discount) {
        vector<string> v;
        for (int i = 0; i < sentence.size(); i++) {
            string t;
            int j = i;
            while (j < sentence.size() && sentence[j] != ' ') {
                t.push_back(sentence[j]);
                j++;
            }
            i = j;
            v.push_back(t);
        }
        string res;
        for (auto &s: v) {
            if (!check(s)) res += s + ' ';
            else {
                res.push_back('$');
                long long price = 0;
                for (int i = 1; i < s.size(); i++) price = price * 10 + s[i] - '0';
                double x = (100 - discount) / 100.0 * (double) price;
                stringstream ss;
                ss.setf(ios::fixed);
                ss.precision(2);
                ss << x;
                res += ss.str();
                res.push_back(' ');
            }
        }
        res.pop_back();
        return res;
    }
};