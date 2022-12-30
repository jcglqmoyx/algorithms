#include <vector>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int> &arr) {
        int n = (int) arr.size();
        int i = 0, j = 0;
        for (; i < n; i++) {
            if (arr[i]) j++;
            else j += 2;
            if (j >= n) break;
        }
        if (j == n + 1) arr[j - 2] = 0, j -= 3, i--;
        else j--;
        while (~i) {
            if (arr[i]) arr[j] = arr[i], j--;
            else arr[j] = arr[j - 1] = arr[i], j -= 2;
            i--;
        }
    }
};