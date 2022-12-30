#include <bits/stdc++.h>

using namespace std;

class Solution {
    using VI = vector<int>;
    using VVI = vector<VI>;
public:
    int maxCandies(VI &status, VI &candies, VVI &keys, VVI &containedBoxes, VI &initialBoxes) {
        int res = 0;
        unordered_set<int> S;
        for (int box: initialBoxes) {
            S.insert(box);
        }
        while (!S.empty()) {
            unordered_set<int> temp;
            bool flag = false;
            for (int x: S) {
                if (!status[x]) {
                    temp.insert(x);
                    continue;
                }
                flag = true;
                res += candies[x];
                for (int y: containedBoxes[x]) temp.insert(y);
                for (int y: keys[x]) {
                    status[y] = 1;
                }
            }
            if (!flag) break;
            S = temp;
        }
        return res;
    }
};