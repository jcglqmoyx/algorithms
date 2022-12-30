#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shortestSequence(vector<int> &rolls, int k) {
        int n = (int) rolls.size(), res = 1;
        unordered_set<int> S;
        for (int i = 0; i < n; i++) {
            int j = i;
            while (j < n && S.size() < k) {
                S.insert(rolls[j++]);
            }
            if (S.size() == k) res++;
            S.clear();
            i = j - 1;
        }
        return res;
    }
};