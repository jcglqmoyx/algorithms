#include <bits/stdc++.h>

using namespace std;

class Solution {
    pair<int, int> work(string s) {
        if (s[0] != '+' && s[0] != '-') s = '+' + s;
        int n = (int) s.size();
        int k = 0, b = 0;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            while (j < n && isdigit(s[j])) j++;
            int c = 1;
            if (j > i + 1) {
                c = stoi(s.substr(i + 1, j - i - 1));
            }
            if (s[i] == '-') c = -c;
            if (j < n && s[j] == 'x') {
                k += c;
                i = j;
            } else {
                b += c;
                i = j - 1;
            }
        }
        return {k, b};
    }

public:
    string solveEquation(string equation) {
        size_t idx = equation.find('=');
        auto l = work(equation.substr(0, idx)), r = work(equation.substr(idx + 1));
        int a = l.first - r.first, b = r.second - l.second;
        if (!a) {
            if (!b) return "Infinite solutions";
            else return "No solution";
        } else {
            return "x=" + to_string(b / a);
        }
    }
};