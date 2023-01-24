from typing import List


class Solution:
    def snakesAndLadders(self, board: List[List[int]]) -> int:
        n, m = len(board), len(board[0])

        def get_pos(idx: int) -> tuple[int, int]:
            r = n - 1 - (idx - 1) // m
            c = (idx - 1) % m
            if (r & 1) == (n & 1):
                c = m - 1 - c
            return r, c

        dist = [float('inf')] * (n * m + 1)
        dist[1] = 0
        q = [(1, 0)]
        while q:
            p, d = q[0]
            q = q[1:]
            for i in range(1, 7):
                ne = p + i
                if ne > n * m:
                    break
                x, y = get_pos(ne)
                if board[x][y] != -1:
                    ne = board[x][y]
                if dist[ne] > d + 1:
                    dist[ne] = d + 1
                    q.append((ne, d + 1))
        return dist[n * m] if dist[n * m] != float('inf') else -1
