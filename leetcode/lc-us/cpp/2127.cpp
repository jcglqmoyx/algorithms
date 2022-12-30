#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumInvitations(vector<int> &favorite) {
        int n = (int) favorite.size();
        int deg[n];
        memset(deg, 0, sizeof deg);
        for (int i = 0; i < n; i++) {
            deg[favorite[i]]++;
        }
        int f[n];
        memset(f, 0, sizeof f);
        bool st[n];
        memset(st, false, sizeof st);

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (!deg[i]) q.push(i);
        }

        while (!q.empty()) {
            int t = q.front();
            q.pop();
            st[t] = true;
            int ne = favorite[t];
            f[ne] = max(f[ne], f[t] + 1);
            if (--deg[ne] == 0) {
                q.push(ne);
            }
        }
        int ring = 0, total = 0;
        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                int ne = favorite[i], nne = favorite[ne];
                if (nne == i) {
                    total += 2 + f[i] + f[ne];
                    st[i] = st[ne] = true;
                } else {
                    int cnt = 1;
                    int j = i;
                    while (favorite[j] != i && !st[j]) {
                        st[j] = true;
                        j = favorite[j];
                        cnt++;
                    }
                    ring = max(ring, cnt);
                }
            }
        }
        return max(ring, total);
    }
};