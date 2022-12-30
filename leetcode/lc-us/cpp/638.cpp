#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        return dfs(price, special, needs);
    }

private:
    map<vector<int>, int> hash;

    int dfs(vector<int> &price, vector<vector<int>> &special, vector<int> &needs) {
        if (hash.count(needs)) return hash[needs];
        int res = 0, n = (int) price.size();
        for (int i = 0; i < n; i++) res += (needs[i] * price[i]);
        for (int i = 0; i < special.size(); i++) {
            bool valid = true;
            for (int j = 0; j < n; j++) {
                if (special[i][j] > needs[j]) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;
            vector<int> tmp(n);
            for (int j = 0; j < n; j++) tmp[j] = needs[j] - special[i][j];
            res = min(res, special[i].back() + dfs(price, special, tmp));
        }
        hash[needs] = res;
        return res;
    }
};