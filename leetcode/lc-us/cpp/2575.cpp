#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = (int) word.size();
        vector<int> res(n);
        for (long long i = 0, x = 0; i < n; i++) {
            x = (x * 10 + word[i] - '0') % m;
            if (!x) res[i] = 1;
        }
        return res;
    }
};