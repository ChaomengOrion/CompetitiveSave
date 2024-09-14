class Solution:
    def convert(self, s: str, numRows: int) -> str:
        map = dict()
        lens = len(s)
        num_per_c = numRows * 2 - 2 if numRows != 1 else 1
        nc = lens // num_per_c
        nr = lens % num_per_c
        
        siter = iter(s)

        for c in range(nc + 1):
            if c != nc:
                c *= 2
                # ↓
                for i in range(numRows):
                    map[(c, i)] = next(siter)
                # ↑
                for i in range(numRows - 2):
                    map[(c+1, numRows-i-2)] = next(siter)
            elif nr <= numRows:
                c *= 2
                # ↓
                for i in range(nr):
                    map[(c, i)] = next(siter)
            else:
                c *= 2
                # ↓
                for i in range(numRows):
                    map[(c, i)] = next(siter)
                # ↑
                for i in range(nr - numRows):
                    map[(c+1, numRows-i-2)] = next(siter)
        sres = []
        for i in range(numRows):
            for j in range((nc + 1)*2):
                if (j, i) in map:
                    sres.append(map[(j, i)])
        return ''.join(sres)

print(Solution.convert(None, "ABCD", 2))