impl Solution {
    pub fn count_substrings(s: String, t: String) -> i32 {
        fn count(s: &[u8], t: &[u8], mut i: usize, mut j: usize) -> i32 {
            let (mut ret, mut prev, mut curr, m, n) = (0, 0, 0, s.len(), t.len());
            while i < m && j < n {
                curr += 1;
                if s[i] != t[j] {
                    prev = curr;
                    curr = 0;
                }
                ret += prev;
                i += 1;
                j += 1;
            }
            ret
        }
        (1..t.len()).fold((0..s.len()).fold(0, |ret, i| ret + count(s.as_bytes(), t.as_bytes(), i, 0)), |ret, j| ret + count(s.as_bytes(), t.as_bytes(), 0, j))
    }
}