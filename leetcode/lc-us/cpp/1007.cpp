#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int res = INF;
        for (int i = 1; i <= 6; i++) {
            res = min(res, cnt(tops, bottoms, i));
            res = min(res, cnt(bottoms, tops, i));
        }
        return res == INF ? -1 : res;
    }

private:
    const int INF = 1e9;

    int cnt(vector<int> &a, vector<int> &b, int number) {
        int flips = 0, n = (int) a.size();
        for (int i = 0; i < n; i++) {
            if (a[i] == number) continue;
            else if (b[i] != number) return INF;
            else flips++;
        }
        return flips;
    }
};