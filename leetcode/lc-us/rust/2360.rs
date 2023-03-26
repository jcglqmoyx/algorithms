use std::cmp::max;

impl Solution {
    pub fn longest_cycle(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut res: i32 = -1;
        let mut time = vec![0; n];
        let mut start = 1;
        for i in 0..n {
            if time[i] == 0 {
                let mut clock = start;
                let mut x = i as i32;
                while x != -1 {
                    if time[x as usize] != 0 {
                        if time[x as usize] >= start {
                            res = max(res, (clock - time[x as usize]) as i32);
                        }
                        break;
                    }
                    time[x as usize] = clock;
                    clock += 1;
                    x = edges[x as usize];
                }
                start = clock;
            }
        }
        res
    }
}