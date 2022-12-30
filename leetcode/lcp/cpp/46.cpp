#include <bits/stdc++.h>

using namespace std;

const int N = 50010;

int h[N], e[N << 1], ne[N << 1], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
    using LL = long long;
    using VI = vector<int>;
    using VVI = vector<vector<int>>;
public:
    VI volunteerDeployment(VI &final_cnt, LL tot, VVI &edges, VVI &plans) {
        memset(h, -1, sizeof h), memset(ne, 0, sizeof ne), idx = 0;
        int n = (int) final_cnt.size() + 1;
        vector<LL> cnt(n), f(n);
        f[0] = 1;
        for (int i = 1; i < n; i++) cnt[i] = final_cnt[i - 1];
        for (auto &edge: edges) {
            int x = edge[0], y = edge[1];
            add(x, y), add(y, x);
        }
        for (int i = (int) plans.size() - 1; ~i; i--) {
            auto &p = plans[i];
            int num = p[0], index = p[1];
            if (num == 1) {
                cnt[index] *= 2;
                f[index] *= 2;
            } else {
                for (int j = h[index]; ~j; j = ne[j]) {
                    int k = e[j];
                    if (num == 2) {
                        cnt[k] -= cnt[index];
                        f[k] -= f[index];
                    } else if (num == 3) {
                        cnt[k] += cnt[index];
                        f[k] += f[index];
                    }
                }
            }
        }
        LL ft = 0;
        for (int i = 0; i < n; i++) {
            tot -= cnt[i];
            ft += f[i];
        }
        LL x = tot / ft;
        for (int i = 0; i < n; i++) cnt[i] += f[i] * x;
        vector<int> res = vector<int>(cnt.begin(), cnt.end());
        return res;
    }
};