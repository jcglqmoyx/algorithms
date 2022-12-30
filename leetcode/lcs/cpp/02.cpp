#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int halfQuestions(vector<int> &questions) {
        int n = (int) questions.size();
        int cnt[1001] = {};
        for (int q: questions) cnt[q]++;
        sort(cnt, cnt + 1001, greater<>());
        int res = 0, sum = 0;
        for (int x: cnt) {
            sum += x;
            res++;
            if (sum >= n / 2) break;
        }
        return res;
    }
};