use std::cmp::max;

struct Trie {
    son: Vec<Vec<usize>>,
    st: Vec<bool>,
    idx: usize,
    max_len: usize,
    cur: String,
}

impl Trie {
    fn new() -> Self {
        let son: Vec<Vec<usize>> = vec![vec![0; 26]; 40010];
        let st: Vec<bool> = vec![false; 40010];
        let idx = 0;
        let max_len: usize = 0;
        let cur: String = String::new();
        Self {
            son,
            st,
            idx,
            max_len,
            cur,
        }
    }
    fn insert(&mut self, s: &str) {
        let mut p: usize = 0;
        let bytes = s.bytes().rev();
        for c in bytes {
            let u = (c - 'a' as u8) as usize;
            if self.son[p][u] == 0 {
                self.idx += 1;
                self.son[p][u] = self.idx;
            }
            p = self.son[p][u];
        }
        self.st[p] = true;
    }
    fn exist(&mut self) -> bool {
        let mut p = 0;
        let mut i = 0;
        for byte in self.cur.bytes().rev() {
            let u = (byte - 'a' as u8) as usize;
            if self.son[p][u] == 0 {
                return false;
            }
            p = self.son[p][u] as usize;
            if self.st[p] {
                return true;
            }
            i += 1;
            if i == self.max_len {
                break;
            }
        }
        return false;
    }
}

struct StreamChecker {
    trie: Trie,
}

impl StreamChecker {
    fn new(words: Vec<String>) -> Self {
        let mut trie = Trie::new();
        for word in words.iter() {
            trie.insert(word);
            trie.max_len = max(trie.max_len, word.len());
        }
        Self {
            trie
        }
    }

    fn query(&mut self, letter: char) -> bool {
        self.trie.cur.push(letter);
        self.trie.exist()
    }
}