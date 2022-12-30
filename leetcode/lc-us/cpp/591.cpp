#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string code) {
        stack<string> stk;
        for (int i = 0; i < code.size(); i++) {
            if (code[i] == '<' && code.substr(i, 9) != "<![CDATA[") {
                int j = i + 1;
                string tag_name;
                bool is_end = false;
                while (j < code.size() && code[j] != '>') {
                    char c = code[j++];
                    if (c == '/' && j == i + 2) {
                        is_end = true;
                        continue;
                    }
                    if (c < 'A' || c > 'Z') return false;
                    tag_name += c;
                }
                if (j == code.size()) return false;
                if (tag_name.empty() || tag_name.size() > 9) return false;

                if (is_end) {
                    if (stk.empty() || stk.top() != tag_name) return false;
                    stk.pop();
                } else {
                    if (i && stk.empty()) return false;
                    stk.push(tag_name);
                }
                i = j;
            } else {
                if (stk.empty()) return false;
                if (code.substr(i, 9) == "<![CDATA[") {
                    int j = i;
                    while (j < code.size() && code.substr(j, 3) != "]]>") j++;
                    if (j == code.size()) return false;
                    i = j + 2;
                }
            }
        }
        return stk.empty();
    }
};