#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = (int) cardPoints.size();
        int sum = 0;
        for (int i = n - k; i < n; i++) {
            sum += cardPoints[i];
        }
        int res = sum;
        for (int i = n - k + 1; i <= n; i++) {
            sum -= cardPoints[(i + n - 1) % n];
            sum += cardPoints[(i + k + n - 1) % n];
            res = max(res, sum);
        }
        return res;
    }
};