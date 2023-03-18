impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        let mut l = 0;
        let mut r = s.len() - 1;
        let bytes = s.as_bytes();
        while l < r {
            while l <= r && !bytes[l].is_ascii_alphanumeric() {
                l += 1;
            }
            while r >= l && !bytes[r].is_ascii_alphanumeric() {
                r -= 1;
            }
            if l >= r {
                return true;
            }
            if bytes[l].to_ascii_lowercase() != bytes[r].to_ascii_lowercase() {
                return false;
            }
            l += 1;
            r -= 1;
        }
        true
    }
}