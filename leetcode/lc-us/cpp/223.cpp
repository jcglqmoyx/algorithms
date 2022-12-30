#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlap_area = overlap(A, B, C, D, E, F, G, H);
        return (C - A) * (D - B) - overlap_area + (G - E) * (H - F); // in order to prevent integer overflow
    }

    int overlap(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (E >= C || F >= D || A >= G || B >= H) return 0;
        return (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
    }
};