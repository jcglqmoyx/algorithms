#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string product;
        int m = (int) num1.size(), n = (int) num2.size();
        vector<int> arr(m + n);
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int a = num1[i] - 48, b = num2[j] - 48;
                arr[i + j + 1] += a * b;
            }
        }
        int carry = 0;
        for (int i = m + n - 1; i >= 1; i--) {
            int sum = arr[i] + carry;
            arr[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) arr[0] = carry;
        for (int i = m + n - 1; i >= 0; i--) {
            product.push_back((char) (arr[i] + '0'));
        }
        while (product.back() == '0' && product.size() > 1) product.pop_back();
        reverse(product.begin(), product.end());
        return product;
    }
};