from sortedcontainers import SortedList


class MKAverage:
    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k
        self.s = 0
        self.q = []
        self.low = SortedList()
        self.mid = SortedList()
        self.high = SortedList()

    def addElement(self, num: int) -> None:
        self.q.append(num)
        if self.low and self.low[-1] > num:
            self.low.add(num)
        elif self.high and self.high[0] < num:
            self.high.add(num)
        else:
            self.mid.add(num)
            self.s += num
        while len(self.low) > self.k:
            self.mid.add(self.low[-1])
            self.s += self.low[-1]
            self.low.remove(self.low[-1])
        while len(self.high) > self.k:
            self.mid.add(self.high[0])
            self.s += self.high[0]
            self.high.remove(self.high[0])
        if len(self.q) > self.m:
            if self.q[0] in self.low:
                self.low.remove(self.q[0])
            elif self.q[0] in self.high:
                self.high.remove(self.q[0])
            else:
                self.s -= self.q[0]
                self.mid.remove(self.q[0])
            self.q = self.q[1:]
        if len(self.q) == self.m:
            while len(self.low) < self.k:
                self.low.add(self.mid[0])
                self.s -= self.mid[0]
                self.mid.remove(self.mid[0])
            while len(self.high) < self.k:
                self.high.add(self.mid[-1])
                self.s -= self.mid[-1]
                self.mid.remove(self.mid[-1])

    def calculateMKAverage(self) -> int:
        if len(self.q) < self.m:
            return -1
        return self.s // (self.m - self.k * 2)
