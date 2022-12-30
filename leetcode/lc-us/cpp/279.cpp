#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect_numbers;
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            if (n == square) return 1;
            perfect_numbers.push_back(square);
        }
        int temp = n;
        while (temp % 4 == 0) temp /= 4;
        if (temp % 8 == 7) return 4;
        for (int i = 0; i < perfect_numbers.size(); i++) {
            for (int j = i; j < perfect_numbers.size(); j++) {
                if (perfect_numbers[i] + perfect_numbers[j] == n) return 2;
            }
        }
        return 3;
    }
};