class Solution {
public:
    int exchangeBits(int num) {
        int odd = num & 0x55555555, even = num & 0xaaaaaaaa;
        odd <<= 1;
        even >>= 1;
        return odd | even;
    }
};