#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        string t;
        for (char c: s) {
            if (c == ']' && !t.empty() && t.back() == '[') t.pop_back();
            else t.push_back(c);
        }
        int n = (int) t.size();
        n >>= 1;
        return (n + 1) / 2;
    }
};