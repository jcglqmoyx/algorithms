#include <bits/stdc++.h>

using namespace std;

class RLEIterator {
public:
    RLEIterator(vector<int> &encoding) {
        nums = encoding;
        i = 0, j = 0;
    }

    int next(int n) {
        while (i < nums.size()) {
            if (n > nums[i] - j) {
                n -= nums[i] - j;
                i += 2;
                j = 0;
            } else {
                j += n;
                return nums[i + 1];
            }
        }
        return -1;
    }

private:
    int i, j;
    vector<int> nums;
};