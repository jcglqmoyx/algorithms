#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
        int n = (int) A.size();
        vector<int> res(n);
        int cnt[n + 1];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0, t = 0; i < n; i++) {
            cnt[A[i]]++, cnt[B[i]]++;
            if (cnt[A[i]] == 2) t++;
            if (cnt[B[i]] == 2 && A[i] != B[i]) t++;
            res[i] = t;
        }
        return res;
    }
};