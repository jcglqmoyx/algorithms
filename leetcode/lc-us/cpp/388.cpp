#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> s;
        int n = (int) input.size(), res = 0;
        for (int i = 0, sum = 0; i < n; i++) {
            int k = 0;
            while (i < n && input[i] == '\t') i++, k++;
            while (s.size() > k) sum -= s.top(), s.pop();
            int j = i;
            while (j < n && input[j] != '\n') j++;
            int len = j - i;
            s.push(len), sum += len;
            if (input.substr(i, len).find('.') != -1) res = max(res, sum + (int) s.size() - 1);
            i = j;
        }
        return res;
    }
};