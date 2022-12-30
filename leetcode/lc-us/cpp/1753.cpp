#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int arr[3] = {a, b, c};
        sort(arr, arr + 3);
        a = arr[0];
        b = arr[1];
        c = arr[2];
        if (c > a + b) return a + b;
        else return (a + b + c) / 2;
    }
};