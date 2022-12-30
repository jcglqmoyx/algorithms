#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int> &A, int m, vector<int> &B, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while (i >= 0 || j >= 0) {
            if (i >= 0 && j >= 0)
                if (A[i] > B[j]) A[index--] = A[i--];
                else A[index--] = B[j--];
            else if (i >= 0) A[index--] = A[i--];
            else A[index--] = B[j--];
        }
    }
};