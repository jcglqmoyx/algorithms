#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthLargestValue(vector<vector<int>> &matrix, int k) {
        int n = (int) matrix.size(), m = (int) matrix[0].size();
        for (int j = 1; j < m; j++) matrix[0][j] ^= matrix[0][j - 1];
        for (int i = 1; i < n; i++) matrix[i][0] ^= matrix[i - 1][0];
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                matrix[i][j] ^= matrix[i - 1][j] ^ matrix[i][j - 1] ^ matrix[i - 1][j - 1];
        vector<int> result(n * m);
        int index = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) result[index++] = matrix[i][j];
        sort(result.begin(), result.end());
        return result[result.size() - k];
    }
};