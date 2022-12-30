#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int captureForts(vector<int> &forts) {
        int n = (int) forts.size();
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (forts[i] == 1) {
                int j = i + 1;
                while (j < n && forts[j] == 0) j++;
                if (j < n && forts[j] == -1) res = max(res, j - i - 1);
                i = j - 1;
            } else if (forts[i] == -1) {
                int j = i + 1;
                while (j < n && forts[j] == 0) j++;
                if (j < n && forts[j] == 1) res = max(res, j - i - 1);
                i = j - 1;
            }
        }
        return res;
    }
};