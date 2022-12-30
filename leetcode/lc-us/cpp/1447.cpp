#include <bits/stdc++.h>

using namespace std;

class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

public:
    vector<string> simplifiedFractions(int n) {
        vector<string> fractions;
        unordered_set<string> s;
        for (int j = 2; j <= n; j++) {
            for (int i = 1; i < j; i++) {
                int x = gcd(i, j);
                int a = i / x, b = j / x;
                string fraction = to_string(a) + '/' + to_string(b);
                if (!s.count(fraction)) {
                    fractions.push_back(fraction);
                    s.insert(fraction);
                }
            }
        }
        return fractions;
    }
};