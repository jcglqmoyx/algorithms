#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        for (int i = 0; i < n; i++) perm[i] = i;
        vector<int> initial = perm;
        vector<int> temp = perm;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) temp[i] = perm[i / 2];
            else temp[i] = perm[n / 2 + (i - 1) / 2];
        }
        perm = temp;
        int step = 1;
        while (!equals(temp, initial)) {
            for (int i = 0; i < n; i++) {
                if (i % 2 == 0) temp[i] = perm[i / 2];
                else temp[i] = perm[n / 2 + (i - 1) / 2];
            }
            step++;
            perm = temp;
        }
        return step;
    }

private:
    static bool equals(vector<int> &a, vector<int> &b) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
};