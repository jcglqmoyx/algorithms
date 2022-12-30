#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution(vector<int> &w) {
        tot = accumulate(w.begin(), w.end(), 0);
        sum.resize(w.size());
        partial_sum(w.begin(), w.end(), sum.begin());
    }

    int pickIndex() {
        int p = rand() % tot + 1;
        int l = 0, r = (int) sum.size() - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (sum[mid] >= p) r = mid;
            else l = mid + 1;
        }
        return l;
    }

private:
    int tot;
    vector<int> sum;
};