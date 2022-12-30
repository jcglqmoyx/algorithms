#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int> &beans) {
        int n = (int) beans.size();
        sort(beans.begin(), beans.end(), greater<>());
        long long sum = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            mx = max(mx, (long long) beans[i] * (i + 1));
            sum += beans[i];
        }
        return sum - mx;
    }
};