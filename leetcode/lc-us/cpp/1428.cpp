#include <bits/stdc++.h>

using namespace std;

class BinaryMatrix {
public:
    int get(int row, int col);

    vector<int> dimensions();
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int m = binaryMatrix.dimensions()[0], n = binaryMatrix.dimensions()[1];
        int ans = n;
        for (int i = 0; i < m; i++) {
            int l = 0, r = n;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (binaryMatrix.get(i, mid)) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l < n) ans = min(ans, l);
        }
        return ans == n ? -1 : ans;
    }
};