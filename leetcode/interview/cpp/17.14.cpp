#include <bits/stdc++.h>

using namespace std;

class Solution {
    int partition(vector<int> &arr, int lo, int hi) {
        int pivot = arr[lo];
        int i = lo + 1, j = hi;
        while (true) {
            while (i <= hi && arr[i] < pivot) i++;
            while (j >= lo && arr[j] > pivot) j--;
            if (i >= j) break;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
        swap(arr[lo], arr[j]);
        return j;
    }

public:
    vector<int> smallestK(vector<int> &arr, int k) {
        int low = 0, high = (int) arr.size() - 1;
        if (k == 0) return {};
        else if (k >= arr.size()) return arr;
        int position = partition(arr, low, high);
        while (low < high) {
            if (position == k) break;
            else if (position < k) {
                low = position + 1;
                position = partition(arr, position + 1, high);
            } else if (position > k) {
                high = position - 1;
                position = partition(arr, low, position - 1);
            }
        }
        vector<int> res(arr.begin(), arr.begin() + k);
        return res;
    }
};