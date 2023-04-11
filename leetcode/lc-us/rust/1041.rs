impl Solution {
    pub fn is_robot_bounded(instructions: String) -> bool {
        let dx = [1, 0, -1, 0];
        let dy = [0, 1, 0, -1];
        let mut x = 0;
        let mut y = 0;
        let mut d = 0;
        for c in instructions.chars() {
            match c {
                'L' => { d = (d + 1) % 4 }
                'R' => { d = (d + 3) % 4 }
                'G' => {
                    x += dx[d];
                    y += dy[d];
                }
                _ => {}
            }
        }
        x == 0 && y == 0 || d != 0
    }
}