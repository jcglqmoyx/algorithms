#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        int k = 0;
        auto n = binary.size();
        while (k < n && binary[k] == '1') k++;
        if (k == n) return binary;
        int cnt = 0;
        for (int i = k + 1; i < n; i++) if (binary[i] == '0') cnt++;
        string res(n, '1');
        res[k + cnt] = '0';
        return res;
    }
};