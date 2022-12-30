#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findString(vector<string> &words, string s) {
        int n = (int) words.size();
        int low = 0, high = n - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (words[mid] == s) return mid;
            int left = mid;
            while (left >= low && words[left].empty()) {
                left--;
            }
            if (left < 0 || words[left] < s) {
                low = mid + 1;
            } else if (words[left] == s) {
                return left;
            } else {
                high = left;
            }
        }
        return words[low] == s ? low : -1;
    }
};