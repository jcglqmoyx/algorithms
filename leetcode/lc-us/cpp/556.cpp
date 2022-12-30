#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long res = stoll(s);
        if (res <= INT32_MAX && res > n) return (int) res;
        return -1;
    }
};