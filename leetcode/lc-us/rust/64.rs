use std::cmp::min;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut f: Vec<Vec<i32>> = vec![vec![0; m]; n];
        f[0][0] = grid[0][0];
        for j in 1..m {
            f[0][j] = f[0][j - 1] + grid[0][j];
        }
        for i in 1..n {
            f[i][0] = f[i - 1][0] + grid[i][0];
        }
        for i in 1..n {
            for j in 1..m {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + grid[i][j];
            }
        }
        return f[n - 1][m - 1];
    }
}