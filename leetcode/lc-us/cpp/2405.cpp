#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = (int) s.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            int mask = 1 << (s[i] - 'a');
            res++;
            int j = i + 1;
            while (j < n) {
                int idx = s[j] - 'a';
                if (mask >> idx & 1) {
                    break;
                }
                mask |= 1 << idx;
                j++;
            }
            i = j - 1;
        }
        return res;
    }
};