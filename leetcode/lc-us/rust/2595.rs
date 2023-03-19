impl Solution {
    pub fn even_odd_bit(n: i32) -> Vec<i32> {
        let mut res = vec![0; 2];
        let mut i = 0;
        let mut n = n;
        while n > 0 {
            if (n & 1) == 1 {
                if (i & 1) == 1 {
                    res[1] += 1;
                } else {
                    res[0] += 1;
                }
            }
            n >>= 1;
            i += 1;
        }
        return res;
    }
}