use std::collections::HashMap;

impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut st: HashMap<char, char> = HashMap::new();
        let mut ts: HashMap<char, char> = HashMap::new();
        for (a, b) in s.chars().zip(t.chars()) {
            if let Some(c) = st.insert(a, b) {
                if b != c {
                    return false;
                }
            }
            if let Some(c) = ts.insert(b, a) {
                if a != c {
                    return false;
                }
            }
        }
        true
    }
}