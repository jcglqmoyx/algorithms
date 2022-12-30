#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int n = (int) a.size(), m = (int) b.size();
        int index1 = (int) a.find('+'), index2 = (int) b.find('+');
        int r1 = stoi(a.substr(0, index1)), r2 = stoi(b.substr(0, index2));
        int i1 = stoi(a.substr(index1 + 1, n - index1 - 1));
        int i2 = stoi(b.substr(index2 + 1, m - index2 - 1));
        return to_string(r1 * r2 - i1 * i2) + '+' + to_string(r1 * i2 + r2 * i1) + 'i';
    }
};