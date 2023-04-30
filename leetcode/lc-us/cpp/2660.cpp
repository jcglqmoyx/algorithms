#include <bits/stdc++.h>

using namespace std;

int get(vector<int> &a) {
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i && a[i - 1] == 10 || i > 1 && a[i - 2] == 10) res += a[i] * 2;
        else res += a[i];
    }
    return res;
}

class Solution {
public:
    int isWinner(vector<int> &p1, vector<int> &p2) {
        int c1 = get(p1), c2 = get(p2);
        if (c1 > c2) return 1;
        else if (c1 < c2)return 2;
        return 0;
    }
};