#include <bits/stdc++.h>

using namespace std;

class Solution {
    using ull = unsigned long long;
    string str;

    bool dfs(int index, ull prev, int cnt) {
        if (index == str.size()) {
            return cnt > 1;
        }
        ull cur = 0;
        for (int i = index; i < str.size(); i++) {
            cur = cur * 10 + str[i] - '0';
            if (cnt == 0 || prev - cur == 1) {
                if (dfs(i + 1, cur, cnt + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool splitString(string s) {
        str = std::move(s);
        return dfs(0, 0, 0);
    }
};