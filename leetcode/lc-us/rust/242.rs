impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        let mut cnt = vec![0; 26];
        for c in s.bytes() {
            cnt[c as usize - 'a' as usize] += 1;
        }
        for c in t.bytes() {
            cnt[c as usize - 'a' as usize] -= 1;
        }
        for i in 0..26 {
            if cnt[i] != 0 {
                return false;
            }
        }
        true
    }
}