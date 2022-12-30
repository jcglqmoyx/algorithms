#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int p[N];
bool st[N];

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        sort(meetings.begin(), meetings.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[2] < b[2];
        });
        for (int i = 0; i < n; i++) p[i] = i, st[i] = false;
        add(0, firstPerson);
        st[0] = st[firstPerson] = true;

        for (int i = 0; i < meetings.size(); i++) {
            int j = i + 1;
            while (j < meetings.size() && meetings[j][2] == meetings[i][2]) j++;
            for (int k = i; k < j; k++) add(meetings[k][0], meetings[k][1]);
            for (int k = i; k < j; k++) {
                int root = find(0);
                int x = meetings[k][0], y = meetings[k][1];
                int px = find(x);
                if (px != root) {
                    p[x] = x, p[y] = y;
                } else {
                    st[x] = st[y] = true;
                }
            }
            i = j - 1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) if (st[i]) res.push_back(i);
        return res;
    }

private:
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    void add(int x, int y) {
        int px = find(x), py = find(y);
        if (px != py) {
            p[px] = py;
        }
    }
};