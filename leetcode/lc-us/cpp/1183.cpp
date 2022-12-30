#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        vector<int> v;
        int vertical = height / sideLength, horizontal = width / sideLength;
        int base = vertical * horizontal;
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                int cnt = base;
                bool flag = false;
                if (i + 1 <= height % sideLength) cnt += horizontal, flag = true;
                if (j + 1 <= width % sideLength) {
                    cnt += vertical;
                    if (flag) cnt++;
                }
                v.push_back(cnt);
            }
        }
        sort(v.begin(), v.end(), greater<>());
        int res = 0;
        for (int i = 0; i < maxOnes; i++) {
            res += v[i];
        }
        return res;
    }
};