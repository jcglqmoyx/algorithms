#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int> &satisfaction) {
        if (*max_element(satisfaction.begin(), satisfaction.end()) <= 0) return 0;
        sort(satisfaction.begin(), satisfaction.end(), greater<>());
        int n = (int) satisfaction.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + satisfaction[i - 1];
        int res = satisfaction[0], sum = satisfaction[0];
        for (int len = 2; len <= n; len++) {
            sum += s[len];
            if (sum > res) res = sum;
            else break;
        }
        return res;
    }
};