#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = (int) encodedText.size();
        int width = n / rows;
        vector<string> v;
        for (int i = 0; i < n; i += width) v.push_back(encodedText.substr(i, width));
        string res;
        for (int j = 0; j < width; j++) {
            for (int i = 0, k = j; i < rows && k < width; i++) {
                res.push_back(v[i][k++]);
            }
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};