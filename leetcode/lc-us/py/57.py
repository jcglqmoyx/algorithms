from typing import List


class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        left, right = newInterval
        placed = False
        res = list()
        for interval in intervals:
            if interval[0] > right:
                if not placed:
                    res.append([left, right])
                    placed = True
                res.append(interval)
            elif interval[1] < left:
                res.append(interval)
            else:
                left = min(left, interval[0])
                right = max(right, interval[1])
        if not placed:
            res.append([left, right])
        return res
