#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int> &g, vector<int> &s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int content_children = 0;
        int index = 0;
        for (int child: g) {
            for (int i = index; i < s.size(); i++) {
                if (s[i] >= child) {
                    index = i + 1;
                    content_children++;
                    if (i == (int) s.size() - 1) {
                        return content_children;
                    }
                    break;
                }
            }
        }
        return content_children;
    }
};