#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxCount(vector<int> &banned, int n, int maxSum) {
        unordered_set<int> S;
        for (int x: banned) S.insert(x);
        int sum = 0, res = 0;
        for (int i = 1; i <= n; i++) {
            if (!S.count(i)) {
                if (sum + i <= maxSum) {
                    sum += i;
                    res++;
                } else {
                    break;
                }
            }
        }
        return res;
    }
};