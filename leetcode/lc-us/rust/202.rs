use std::collections::HashSet;

impl Solution {
    pub fn is_happy(n: i32) -> bool {
        let mut set: HashSet<i32> = HashSet::new();
        let mut n = n;
        while n != 1 {
            let mut s = 0;
            while n > 0 {
                let d = n % 10;
                s += d * d;
                n /= 10;
            }
            if set.contains(&s) {
                return false;
            }
            set.insert(s);
            n = s;
        }
        true
    }
}