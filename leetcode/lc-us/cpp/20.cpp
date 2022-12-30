#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        int map[128] = {0};
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';
        for (char c: s) {
            if (c == '(' || c == '[' || c == '{') {
                chars.push(c);
            } else {
                if (chars.empty()) {
                    return false;
                }
                char top = chars.top();
                if (map[top] != c) {
                    return false;
                }
                chars.pop();
            }
        }
        return chars.empty();
    }
};