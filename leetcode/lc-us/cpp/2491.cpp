#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int> &skill) {
        using LL = long long;
        int n = (int) skill.size();
        int sum = 0;
        for (int x: skill) sum += x;
        if (sum % (n / 2)) return -1;
        int sub = sum / (n / 2);
        unordered_map<int, int> cnt;
        LL res = 0;
        for (int x: skill) {
            if (cnt.count(sub - x)) {
                cnt[sub - x]--;
                if (cnt[sub - x] == 0) cnt.erase(sub - x);
                res += (LL) x * (sub - x);
            } else {
                cnt[x]++;
            }
        }
        if (!cnt.empty()) return -1;
        return res;
    }
};