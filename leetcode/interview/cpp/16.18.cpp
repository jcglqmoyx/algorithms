#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int n = (int) pattern.size(), m = (int) value.size();
        int cnt_a = 0, cnt_b = 0;
        for (char c: pattern) {
            if (c == 'a') cnt_a++;
            else if (c == 'b') cnt_b++;
        }
        if (cnt_a == 0 || cnt_b == 0) {
            if (!m) return true;
            if (m % n) return false;
            int len = m / n;
            string s = value.substr(0, len);
            for (int i = len; i < m; i += len) {
                if (value.substr(i, len) != s) {
                    return false;
                }
            }
            return true;
        }
        for (int len_a = 0;; len_a++) {
            if (cnt_a * len_a > m) break;
            if ((m - len_a * cnt_a) % cnt_b) continue;
            int len_b = (m - len_a * cnt_a) / cnt_b;
            unordered_map<char, string> hash;
            int idx = 0;
            bool valid = true;
            for (char c: pattern) {
                if (c == 'a') {
                    if (!hash.count('a')) {
                        hash['a'] = value.substr(idx, len_a);
                    } else if (hash['a'] != value.substr(idx, len_a)) {
                        valid = false;
                        break;
                    }
                    idx += len_a;
                } else {
                    if (!hash.count('b')) {
                        hash['b'] = value.substr(idx, len_b);
                    } else if (hash['b'] != value.substr(idx, len_b)) {
                        valid = false;
                        break;
                    }
                    idx += len_b;
                }
            }
            if (valid) {
                if (hash.count('a') && hash.count('b') && hash['a'] != hash['b']) {
                    return true;
                }
            }
        }
        return false;
    }
};