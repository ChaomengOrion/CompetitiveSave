def get(m):
    no = set([9])
    ans = []
    def trydiv(n):
        add = 0
        while n > 0:
            n -= 1
            add += 1
            if n not in no and add not in no:
                ans.append(add)
                #print(n, add, no)
                for cn in no.copy():
                    newa = cn - add
                    if (newa > 0):
                        no.add(newa)
                trydiv(n)
                return
        return
    trydiv(m)
    return ans

for i in range(1, 300):
    ans = get(i)
    if (i % 2 == 0):
        print(i, i // 2)
    else:
        print(i, (i - 11) // 2 + 1, len(ans), ans)