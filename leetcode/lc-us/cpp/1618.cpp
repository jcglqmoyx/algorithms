#include <bits/stdc++.h>

using namespace std;

class FontInfo {
public:
    // Return the width of char ch when fontSize is used.
    int getWidth(int fontSize, char ch);

    // Return Height of any char when fontSize is used.
    int getHeight(int fontSize);
};

class Solution {
public:
    int maxFont(string text, int w, int h, vector<int> &fonts, FontInfo fontInfo) {
        _w = w, _h = h;
        memset(cnt, 0, sizeof cnt);
        for (char c: text) cnt[c]++;
        int l = -1, r = (int) fonts.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(fonts, mid, fontInfo)) l = mid;
            else r = mid - 1;
        }
        return l == -1 ? -1 : fonts[l];
    }

private:
    int _w, _h;
    int cnt[123];

    inline bool check(vector<int> &fonts, int idx, FontInfo &fontInfo) const {
        long long total_width = 0LL;
        for (char c = 'a'; c <= 'z'; c++) {
            if (fontInfo.getHeight(fonts[idx]) > _h) return false;
            total_width += fontInfo.getWidth(fonts[idx], c) * cnt[c];
        }
        return total_width <= _w;
    }
};