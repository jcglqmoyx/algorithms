impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        s.bytes().rev().skip_while(|&c| c == b' ').take_while(|&c| c != b' ').count() as i32
    }
}