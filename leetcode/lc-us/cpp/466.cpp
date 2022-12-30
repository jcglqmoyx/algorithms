#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int n = (int) s1.size(), m = (int) s2.size();
        unordered_map<int, pair<int, int>> hash;
        hash[0] = {-1, 0};
        int res = 0;
        for (int i = 0, cnt = 0, k = 0; i < n1; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[j] == s2[k]) k++;
                if (k == m) cnt++, k = 0;
            }
            if (hash.count(k)) {
                auto &last = hash[k];
                int period = i - last.first;
                res = (n1 - last.first - 1) / period * (cnt - last.second) + last.second;
                i += (n1 - i - 1) / period * period + 1;
                while (i < n1) {
                    for (int j = 0; j < n; j++) {
                        if (s1[j] == s2[k]) k++;
                        if (k == m) k = 0, res++;
                    }
                    i++;
                }
                res /= n2;
                break;
            } else {
                hash[k] = {i, cnt};
                res = cnt / n2;
            }
        }
        return res;
    }
};