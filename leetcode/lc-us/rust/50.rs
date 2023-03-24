fn pow(a: f64, n: i64) -> f64 {
    let mut a = a;
    let mut res = 1.0;
    let mut n = n;
    while n > 0 {
        if (n & 1) == 1 {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

impl Solution {
    pub fn my_pow(x: f64, n: i32) -> f64 {
        let mut n: i64 = n as i64;
        if n < 0 {
            1.0 / pow(x, -n)
        } else {
            pow(x, n)
        }
    }
}