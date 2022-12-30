#include <bits/stdc++.h>

using namespace std;

class Solution {
    int map[128] = {};

    int partition(string &s, int low, int high) {
        if (low >= high) return low;
        char pivot = s[low];
        int i = low + 1, j = high;
        while (true) {
            while (i < high && (map[s[i]] > map[pivot] || (map[s[i]] == map[pivot] && s[i] > pivot))) i++;
            while (j > low && (map[s[j]] < map[pivot] || (map[s[j]] == map[pivot] && s[j] < pivot))) j--;
            if (i >= j) break;
            swap(s[i], s[j]);
            i++;
            j--;
        }
        swap(s[low], s[j]);
        return j;
    }

    void quicksort(string &s, int low, int high) {
        if (low >= high) return;
        int position = partition(s, low, high);
        quicksort(s, low, position - 1);
        quicksort(s, position + 1, high);
    }

public:
    string frequencySort(string s) {
        for (char c: s) map[c]++;
        quicksort(s, 0, (int) s.length() - 1);
        return s;
    }
};