#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double minRecSize(vector<vector<int>> &f) {
        int n = (int) f.size();
        vector<int> k(n, 0), b(n, 0);
        sort(f.begin(), f.end());
        for (int i = 0; i < n; i++) {
            k[i] = f[i][0];
            b[i] = f[i][1];
        }
        int p = 0, q = 0;
        while (q < n && k[q] == k[p]) q++;
        if (q >= n) return 0.;
        double x_min = 1e100, x_max = -1e100;
        double y_min = 1e100, y_max = -1e100;
        for (; q < n;) {
            int r = q;
            while (r + 1 < n && k[r + 1] == k[q]) r++;
            double cx1 = 1.0 * (b[r] - b[p]) / (k[r] - k[p]);
            double cx2 = 1.0 * (b[q] - b[q - 1]) / (k[q] - k[q - 1]);
            x_min = min(x_min, min(cx1, cx2));
            x_max = max(x_max, max(cx1, cx2));
            double cy1 = 1.0 * (b[r] * k[p] - b[p] * k[r]) / (k[r] - k[p]);
            double cy2 = 1.0 * (b[q] * k[q - 1] - b[q - 1] * k[q]) / (k[q] - k[q - 1]);
            y_min = min(y_min, min(cy1, cy2));
            y_max = max(y_max, max(cy1, cy2));
            p = q;
            while (q < n && k[q] == k[p]) q++;
        }
        return (x_max - x_min) * (y_max - y_min);
    }
};