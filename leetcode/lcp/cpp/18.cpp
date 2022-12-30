#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int breakfastNumber(vector<int> &staple, vector<int> &drinks, int x) {
        int count = 0;
        sort(staple.begin(), staple.end());
        sort(drinks.begin(), drinks.end());
        if (staple.size() > drinks.size()) swap(staple, drinks);
        for (int i: staple) {
            if (i >= x) break;
            int idx = binary_search(drinks, (int) drinks.size(), x - i);
            count = (count + idx) % 1000000007;
        }
        return count;
    }

private:
    int binary_search(vector<int> &arr, int high, int target) {
        int low = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] <= target) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};