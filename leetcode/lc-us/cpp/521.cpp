#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : max((int) a.size(), (int) b.size());
    }
};