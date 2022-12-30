#include <bits/stdc++.h>

using namespace std;

class Solution {
    typedef long long LL;

    vector<int> get(string &s, LL a, LL b) {
        vector<int> res = {(int) a, (int) b};
        string t = to_string(a) + to_string(b);
        while (t.size() < s.size()) {
            auto c = a + b;
            if (c > INT32_MAX) return {};
            t += to_string(c);
            res.push_back((int) c);
            a = b, b = c;
        }
        if (t != s) return {};
        return res;
    }

public:
    vector<int> splitIntoFibonacci(string num) {
        for (int i = 1; i <= 10 && i < num.size(); i++) {
            for (int j = i + 1; j <= i + 10 && j < num.size(); j++) {
                LL a = stoll(num.substr(0, i)), b = stoll(num.substr(i, j - i));
                auto res = get(num, a, b);
                if (!res.empty()) return res;
            }
        }
        return {};
    }
};