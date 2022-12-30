#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reformat(string s) {
        vector<char> letters, digits;
        for (char c: s) {
            if (isalpha(c)) {
                letters.push_back(c);
            } else {
                digits.push_back(c);
            }
        }
        if (abs((int) letters.size() - (int) digits.size()) > 1) {
            return "";
        }
        string res;
        if (letters.size() > digits.size()) {
            int i = 0, j = 0;
            while (i < letters.size() || j < digits.size()) {
                if (i < letters.size() && j < digits.size()) {
                    res.push_back(letters[i++]);
                    res.push_back(digits[j++]);
                } else if (i < letters.size()) {
                    res.push_back(letters[i++]);
                } else {
                    res.push_back(digits[j++]);
                }
            }
        } else {
            int i = 0, j = 0;
            while (i < letters.size() || j < digits.size()) {
                if (i < letters.size() && j < digits.size()) {
                    res.push_back(digits[j++]);
                    res.push_back(letters[i++]);
                } else if (i < letters.size()) {
                    res.push_back(letters[i++]);
                } else {
                    res.push_back(digits[j++]);
                }
            }
        }
        return res;
    }
};