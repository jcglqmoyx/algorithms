class Solution {
public:
    int bitwiseComplement(int n) {
        int temp = 1;
        while (temp < n) {
            temp = (temp << 1) + 1;
        }
        return temp ^ n;
    }
};