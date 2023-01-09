#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        const int N = 1e4, M = 1e9;
        bool bulky = false;
        if (length >= N || width >= N || height >= N || 1LL * length * width * height >= M) {
            bulky = true;
        }
        bool heavy = mass >= 100;
        if (bulky && heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";
        return "Neither";
    }
};