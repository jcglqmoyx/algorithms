impl Solution {
    pub fn pivot_integer(n: i32) -> i32 {
        let x = n * (n + 1) / 2;
        let y = (x as f64).sqrt() as i32;
        if y * y == x {
            return y as i32;
        }
        -1
    }
}