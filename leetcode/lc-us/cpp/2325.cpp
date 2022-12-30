#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> M;
        char x = 'a';
        for (char c: key) {
            if (c != ' ') {
                if (!M.count(c)) M[c] = x++;
            }
        }
        string res;
        for (char c: message) {
            if (c == ' ') res.push_back(c);
            else res.push_back(M[c]);
        }
        return res;
    }
};