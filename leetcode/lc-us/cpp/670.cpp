#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = (int) s.size();
        int f[n];
        f[n - 1] = n - 1;
        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[f[i + 1]]) {
                f[i] = i;
            } else {
                f[i] = f[i + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] != s[f[i]]) {
                swap(s[i], s[f[i]]);
                break;
            }
        }
        return stoi(s);
    }
};
