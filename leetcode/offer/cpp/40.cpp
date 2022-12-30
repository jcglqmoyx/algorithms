#include <bits/stdc++.h>

using namespace std;

class Solution {
    int partition(vector<int> &arr, int l, int r) {
        if (l >= r) return l;
        swap(arr[l], arr[(l + r) >> 1]);
        int pivot = arr[l];
        int i = l + 1, j = r;
        while (true) {
            while (i < r && arr[i] < pivot) i++;
            while (j > l && arr[j] > pivot) j--;
            if (i >= j) break;
            swap(arr[i], arr[j]);
            i++, j--;
        }
        swap(arr[l], arr[j]);
        return j;
    }

public:
    vector<int> getLeastNumbers(vector<int> &arr, int k) {
        if (!k) return {};
        int n = (int) arr.size();
        int l = 0, r = n - 1;
        int p = partition(arr, l, r);
        while (p != k - 1) {
            if (p < k - 1) l = p + 1;
            else r = p - 1;
            p = partition(arr, l, r);
        }
        return {arr.begin(), arr.begin() + k};
    }
};