#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth) {
        int n = (int) books.size();
        vector<int> f(n + 1, 1e8);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_height = 0, width = 0;
            for (int j = i; j; j--) {
                width += books[j - 1][0];
                if (width > shelfWidth) break;
                max_height = max(max_height, books[j - 1][1]);
                f[i] = min(f[i], f[j - 1] + max_height);
            }
        }
        return f[n];
    }
};