impl Solution {
    pub fn check_valid_grid(grid: Vec<Vec<i32>>) -> bool {
        if grid[0][0] != 0 {
            return false;
        }
        let n = grid.len();
        let mut v = vec![vec![]; n * n];
        for i in 0..n {
            for j in 0..n {
                v[grid[i][j] as usize] = vec![i as i32, j as i32];
            }
        }
        for i in 0..n * n - 1 {
            let dx = ((v[i][0] - v[i + 1][0]) as i32).abs();
            let dy = ((v[i][1] - v[i + 1][1]) as i32).abs();
            if dx == 1 && dy == 2 || dx == 2 && dy == 1 {
                continue;
            }
            return false;
        }
        return true;
    }
}
