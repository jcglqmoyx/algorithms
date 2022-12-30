#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> power;
        for (int i = 1; i <= 1e9; i <<= 1) {
            string str = to_string(i);
            sort(str.begin(), str.end());
            power.insert(str);
        }
        string str = to_string(n);
        sort(str.begin(), str.end());
        return power.count(str);
    }
};