#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        while (!s.empty() && s.back() == ' ') s.pop_back();
        while (!s.empty() && s.front() == ' ') s.erase(s.begin());
        if (s.empty()) return false;
        bool HAS_E = false;
        bool HAS_DOT = false;
        bool HAS_DIGIT = false;
        int COUNT_PLUS = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                if (toupper(s[i]) == 'E') {
                    if (HAS_E || i == s.size() - 1 || !HAS_DIGIT) return false;
                    else HAS_E = true;
                } else {
                    return false;
                }
            } else if (s[i] == '.') {
                if (HAS_DOT || HAS_E || s.size() == 1 || i && toupper(s[i - 1]) == 'E' ||
                    i == s.size() - 1 && !isdigit(s[i - 1])) {
                    return false;
                } else {
                    HAS_DOT = true;
                }
            } else if (s[i] == '+') {
                if (COUNT_PLUS > 1 || i && s[i - 1] != 'E' && s[i - 1] != 'e' || i == s.size() - 1) {
                    return false;
                }
                COUNT_PLUS++;
            } else if (s[i] == '-') {
                if (i != 0 && s[i - 1] != 'E' && s[i - 1] != 'e' || i == s.size() - 1) return false;
            } else if (isdigit(s[i])) {
                HAS_DIGIT = true;
            } else if (!isdigit(s[i])) return false;
        }
        return true;
    }
};