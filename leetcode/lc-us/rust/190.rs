impl Solution {
    pub fn reverse_bits(x: u32) -> u32 {
        let mut res: u32 = 0;
        for i in 0..32 {
            res <<= 1;
            if (x >> i) & 1 == 1 {
                res += 1;
            }
        }
        res
    }
}