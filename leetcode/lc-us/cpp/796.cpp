#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        return (s + s).find(goal) != string::npos;
    }
};