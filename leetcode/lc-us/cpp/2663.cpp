#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string smallestBeautifulString(string s, int k) {
        int n = (int) s.size();
        auto get = [&]() {
            for (int i = n - 1; i >= 0; i--) {
                for (int c = s[i] + 1; c < 'a' + k; c++) {
                    if (i && s[i - 1] == c || i > 1 && s[i - 2] == c) continue;
                    s[i] = (char) c;
                    return i;
                }
            }
            return -1;
        };
        int pos = get();
        if (pos == -1) return "";
        for (int i = pos + 1; i < n; i++) {
            for (int c = 'a'; c < 'a' + k; c++) {
                if (i > 1 && s[i - 2] == c || s[i - 1] == c) continue;
                s[i] = (char) c;
                break;
            }
        }
        return s;
    }
};