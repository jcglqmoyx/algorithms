#include <bits/stdc++.h>

using namespace std;

class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

public:
    string fractionAddition(string expression) {
        int n = 0;
        for (char ch: expression) if (ch == '/') n++;
        expression = '+' + expression;
        int a = 0, b = 1, c, d, offset = 0;
        char e;
        for (int i = 0; i < n; i++) {
            sscanf(expression.c_str() + offset, "%c%d/%d", &e, &c, &d);
            offset += (e + to_string(c) + '/' + to_string(d)).size();
            if (e == '-') c = -c;
            int x = a * d + b * c, y = b * d;
            int z = gcd(x, y);
            a = x / z, b = y / z;
        }
        if (b < 0) a = -a, b = -b;
        return to_string(a) + '/' + to_string(b);
    }
};