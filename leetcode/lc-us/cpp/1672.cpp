#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>> &accounts) {
        int maximum_wealth = 0;
        for (const vector<int> account: accounts) {
            int wealth = 0;
            for (int n: account) {
                wealth += n;
            }
            maximum_wealth = max(maximum_wealth, wealth);
        }
        return maximum_wealth;
    }
};