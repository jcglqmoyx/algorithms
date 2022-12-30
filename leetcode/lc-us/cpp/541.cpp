#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.length(); i += 2 * k) {
            reverse(s, i, min(i + k - 1, (int) s.length() - 1));
        }
        return s;
    }

private:
    void reverse(string &s, int low, int high) {
        while (low < high) {
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};