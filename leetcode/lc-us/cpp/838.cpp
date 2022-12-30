#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        int n = (int) dominoes.size();
        vector<int> l(n), r(n);
        for (int i = 0, j = 0; i < n; i++) {
            if (dominoes[i] != '.') j = i;
            l[i] = j;
        }
        for (int i = n - 1, j = n - 1; i >= 0; i--) {
            if (dominoes[i] != '.') j = i;
            r[i] = j;
        }
        for (int i = 0; i < n; i++) {
            char L = dominoes[l[i]], R = dominoes[r[i]];
            if (L == 'L' && R == 'R') dominoes[i] = '.';
            else if (L == 'L' && R == 'L') dominoes[i] = 'L';
            else if (L == 'R' && R == 'R') dominoes[i] = 'R';
            else {
                if (i - l[i] < r[i] - i) dominoes[i] = 'R';
                else if (i - l[i] > r[i] - i) dominoes[i] = 'L';
                else dominoes[i] = '.';
            }
        }
        return dominoes.substr(1, n - 2);
    }
};