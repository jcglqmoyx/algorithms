#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        bool st[123] = {};
        for (char c: s) {
            if (st[c]) return c;
            st[c] = true;
        }
        return 'a';
    }
};