a: list = eval(input())
b = []
for n in a:
    if (a.count(n) == 1):
        b.append(n)
b.sort()
print(','.join(map(str, b)))