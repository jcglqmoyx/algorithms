class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        res = 0
        i, n = 0, len(points)
        while i < n:
            res += 1
            j = i + 1
            end = points[i][1]
            while j < n:
                if points[j][0] <= end:
                    end = min(end, points[j][1])
                else:
                    break
                j += 1
            i = j
        return res
