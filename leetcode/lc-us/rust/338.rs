impl Solution {
    pub fn count_bits(n: i32) -> Vec<i32> {
        let n: usize = n as usize;
        let mut res: Vec<i32> = vec![0; n + 1];
        for i in 0..n + 1 {
            res[i] = res[i / 2];
            if (i & 1) == 1 {
                res[i] += 1;
            }
        }
        res
    }
}