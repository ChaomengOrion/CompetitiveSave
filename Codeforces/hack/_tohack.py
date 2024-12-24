from bisect import *

class FenwickTree:
    def __init__(self, x):
        self.bit = x
        for i in range(len(x)):
            j = i | (i + 1)
            if j < len(x):
                x[j] += x[i]

    def update(self, idx, x):
        while idx < len(self.bit):
            self.bit[idx] += x
            idx |= idx + 1

    def query(self, end):
        x = 0
        while end:
            x += self.bit[end - 1]
            end &= end - 1
        return x

t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ranges = [(a[i] + 1, b[i]) for i in range(n)]
    ranges.sort()
    branges = sorted(ranges, key = lambda p: p[1])
    candidates = []
    for el in a:
        candidates.append(el)
        candidates.append(el - 1)
        candidates.append(el + 1)
    for el in b:
        candidates.append(el)
        candidates.append(el - 1)
        candidates.append(el + 1)
    candidates.sort()
    res = 0
    i = 0
    j = 0
    vals = []
    for a, b in ranges:
        vals.append(b)
    for c in candidates:
        vals.append(c)
    vals.sort()
    ends = FenwickTree([0] * (len(vals) + 1))
    total = 0
    for c in candidates:
        while i < len(branges) and branges[i][1] < c:
            i += 1
        while j < len(ranges) and ranges[j][0] <= c:
            ends.update(bisect_left(vals, ranges[j][1]), 1)
            total += 1
            j += 1
        if total - ends.query(bisect_left(vals, c)) <= k:
            res = max(res, (n - i) * c)
    print(res)