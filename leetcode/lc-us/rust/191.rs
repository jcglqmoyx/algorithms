impl Solution {
    pub fn hammingWeight(n: u32) -> i32 {
        let mut n = n;
        let mut res = 0;
        while n != 0 {
            if (n & 1) == 1 {
                res += 1;
            }
            n >>= 1;
        }
        res
    }
}