#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string encode(int num) {
        bitset<32> n(num + 1);
        string str = n.to_string();
        int position = 0;
        for (; position < 32; position++) {
            if (str[position] == '1') break;
        }
        return str.substr(position + 1);
    }
};