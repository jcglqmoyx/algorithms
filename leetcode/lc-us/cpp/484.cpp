#include <bits/stdc++.h>

using namespace std;

class Solution {
    void reverse(vector<int> &res, int start, int end) {
        while (start < end) swap(res[start], res[end]), start++, end--;
    }

public:
    vector<int> findPermutation(string s) {
        int n = (int) s.size();
        vector<int> res(n + 1);
        for (int i = 0; i < n + 1; i++) res[i] = i + 1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'I') i++;
            int j = i;
            while (j < n && s[j] == 'D') j++;
            reverse(res, i, j);
            i = j - 1;
        }
        return res;
    }
};