package main

func isRobotBounded(instructions string) bool {
	dx := []int{1, 0, -1, 0}
	dy := []int{0, 1, 0, -1}
	x, y, d := 0, 0, 0
	for i := 0; i < len(instructions); i++ {
		switch instructions[i] {
		case 'L':
			d = (d + 1) % 4
			break
		case 'R':
			d = (d + 3) % 4
			break
		default:
			x += dx[d]
			y += dy[d]
		}
	}
	return x == 0 && y == 0 || d != 0
}