#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        string a, b, c;
        for (char ch: firstWord) a += to_string(ch - 'a');
        for (char ch: secondWord) b += to_string(ch - 'a');
        for (char ch: targetWord) c += to_string(ch - 'a');
        return stoi(a) + stoi(b) == stoi(c);
    }
};