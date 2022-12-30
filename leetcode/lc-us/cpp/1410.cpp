#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string entityParser(string text) {
        string res;
        for (int i = 0; i < text.size(); i++) {
            if (text.substr(i, 6) == "&quot;") {
                res += "\"";
                i += 5;
            } else if (text.substr(i, 6) == "&apos;") {
                res += '\'';
                i += 5;
            } else if (text.substr(i, 5) == "&amp;") {
                res += '&';
                i += 4;
            } else if (text.substr(i, 4) == "&gt;") {
                res += '>';
                i += 3;
            } else if (text.substr(i, 4) == "&lt;") {
                res += '<';
                i += 3;
            } else if (text.substr(i, 7) == "&frasl;") {
                res += '/';
                i += 6;
            } else res += text[i];
        }
        return res;
    }
};