#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        for (int i = n - 1; i >= 0 && k; i--) {
            int need = min(25, k);
            s[i] += need;
            k -= need;
        }
        return s;
    }
};