#include <bits/stdc++.h>

using namespace std;

class Solution {
    int n;
    vector<int> tr;

    int lowbit(int x) {
        return x & -x;
    }

    void add(int x) {
        for (int i = x; i <= n; i += lowbit(i)) {
            tr[i] += 1;
        }
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i; i -= lowbit(i)) {
            res += tr[i];
        }
        return res;
    }

public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        n = (int) people.size();
        tr.resize(n + 1);
        sort(people.begin(), people.end(), [](vector<int> a, vector<int> b) {
            if (a[0] != b[0]) return a[0] < b[0];
            else return a[1] > b[1];
        });
        vector<vector<int>> res(n);
        for (auto p: people) {
            int k = p[1];
            int l = 1, r = n;
            while (l < r) {
                int mid = l + (r - l) / 2;
                if (mid - query(mid) >= k + 1) r = mid;
                else l = mid + 1;
            }
            res[r - 1] = p;
            add(r);
        }
        return res;
    }
};